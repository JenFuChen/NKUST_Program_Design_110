f = open('input.txt', 'r+')
playersScore = 1
oldscore = (f.read())
oldscore = int(oldscore)
score = oldscore + playersScore
f.seek(0)
f.write(str(score))
f.close()
