import glob

players = []
fil = open("players.txt")
for pl in fil.read().split("\n"):
    if pl != "":
        pseudo = pl.split(" ### ")[0]
        nbr = pl.split(" ### ")[1]
        players.append([pseudo,nbr])
def importHands():
    global players
    allfile =  glob.glob("./hands/*.txt")
    i = 0
    for file in allfile:
        if not "SHORT TRACK" in file:
            fil = open(file, "r")
            hands = fil.read()
            try:
                open(file.replace("hands/", "hands2/")).close()

            except IOError:
                for pl in players:
                    hands = hands.replace(pl[0],pl[1])
                fu = open(file.replace("hands/", "hands2/"),"w")
                fu.write(hands)
                fu.close()
                fil.close()
            i += 1
            #if i % 10 == 0
            print str(i) + " / 7180 files"
            
                #if i > 20:
                #    break

importHands()
