fil = open("winer.txt", "r")
winers = ""
for winer in fil.read().split("\n"):
    winers += winer+"\n"
fil.close()
fil = open("players.txt")
for pl in fil.read().split("\n"):
    pl = pl.lower()
    if pl != "":
        pll = pl.split(" ### ")
        winers = winers.replace(pll[0],pll[1])
fil.close()

print winers
