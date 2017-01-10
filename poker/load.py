# -*- coding: utf-8 -*-
import ctypes
import glob


c = ctypes.cdll.LoadLibrary("./load.so")





'''
1 checks
2 bet
3 call
4 raise
5 fold
'''

winners = []


def isWinner(pseudo):
    global winners
    for pl in winners:
        if pseudo in pl:
            return 1
    return 0
def render(rendu):
    if rendu == "preflop":
        return 1
    if rendu == "flop":
        return 2
    if rendu == "turn":
        return 3
    if rendu == "river":
        return 4
    print "ERREUR RENDU "+rendu
    exit()

def workhand(hand):
    global c



    rendu = "seat"
    nbrplayer = 0
    players = []
    iaction = 0
    for line in hand.split("\n"):
        if " checks" in line or " bets " in line or " calls " in line or " folds" in line or " raises " in line:
            iaction += 1
    if iaction == 0:
        return False
    c.newhand(iaction)
    for line in hand.split("\n"):
        line = line.replace(" and is all-in", "")
        if "*** ANTE/BLINDS ***" in line:
            rendu = "blinds"
            continue
        if "*** PRE-FLOP ***" in line:
            rendu = "preflop"
            continue
        if "*** FLOP ***" in line:
            rendu = "flop"
            c.addflop(line.split("[")[1].split("]")[0].replace(" ", ""))
            continue
        if "*** TURN ***" in line:
            rendu = "turn"
            t = line.split("[")[2].split("]")[0]
            c.addboard(t)
            continue
        if "*** RIVER ***" in line:
            rendu = "river"
            t = line.split("[")[2].split("]")[0]
            c.addboard(t)
            continue
        if "*** SHOW DOWN ***" in line:
            rendu = "show"
            continue
        if "*** SUMMARY ***" in line:
            rendu = "sum"
            continue
        if rendu == "seat":
            if " is the button" in line and ":" in line:
                but = line.split("#")[1][0]
                continue
            if "Seat " in line:
                pseudo = line.split(": ")[1].split(" (")[0]
                jetons = line.split("(")[1].split("€")[0]
                c.addplayer(pseudo, jetons, isWinner(pseudo))
                nbrplayer += 1
                players.append(pseudo)
        if rendu != "seat" and rendu != "show" and rendu != "sum" and rendu != "blinds":
            if " checks" in line:
                pseudo = line.split(" checks")[0]
                c.addaction(players.index(pseudo), 1,render(rendu),"0")
                continue
            if " folds" in line:
                pseudo = line.split(" folds")[0]
                c.addaction(players.index(pseudo), 5, render(rendu), "0")
                continue
            if " bets " in line:
                pseudo = line.split(" bets ")[0]
                jetons = line.split(" bets ")[1].split("€")[0]
                c.addaction(players.index(pseudo), 2, render(rendu), jetons)
                continue
            if " raises " in line:
                pseudo = line.split(" raises ")[0]
                jetons = line.split(" raises ")[1].split(" to ")[1].split("€")[0]
                c.addaction(players.index(pseudo), 4, render(rendu), jetons)
                continue
            if " calls " in line:
                pseudo = line.split(" calls ")[0]
                jetons = line.split(" calls ")[1].split("€")[0]
                c.addaction(players.index(pseudo), 3, render(rendu), jetons)
                continue


def importHands():
    global c
    global winners
    fu = open("players.txt")
    for pl in fu.read().split("\n"):
        c.addpseudo(pl.split(" ### ")[0])
    fu.close()

    fu = open("winerin.txt")
    for pl in fu.read().split("\n"):
        winners.append(pl)
    fu.close()

    allfile =  glob.glob("./hands2/*.txt")
    i = 0
    for file in allfile:
        if not "SHORT TRACK" in file:
            fil = open(file, "r")
            hands = fil.read()

            for hand in hands.split("Winamax Poker"):
                if "Incognito" in hand:
                    break
                hand = "Winamax Poker" + hand
                workhand(hand)

            i += 1
            #if i % 10 == 0:
            #    print str(i) + " / 7180 files"
            fil.close()
            if i > 50:
                break

c.init()
importHands()
