import urllib.request, urllib
def get_challenge(s):
	return urllib.request.urlopen('http://www.pythonchallenge.com/pc/' + s).read()
src = get_challenge('def/equality.html')

count = 0
lcount = 0
ucount = 0
print (src)
for i in src:
	if i == i.uppercase():
		count += 1
	if count == 3 and i == i.lowercase() and ucount == 0:
		lcount += 1
		jew = i
	if count == 3 and i == i.uppercase() and lcount == 1:
		ucount += 1
	if count > 3 or lcount > 1 or ucount > 3:
		count = 0
		lcount = 0
		ucount = 0
	print (jew)