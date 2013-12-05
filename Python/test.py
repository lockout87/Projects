import urllib.request, re, pickle
def get_challenge():
	return urllib.request.urlopen('http://www.manta.com/mb?search=97229&search_source=home').read()
banner = get_challenge()
textfilewrite = open("empty.txt", "wb")
textfileread = open("empty.txt", "rb")
realban = banner.decode('utf-8')
pickle.dump(banner.decode('utf-8'), textfilewrite)
Del1 = "\">"
Del2 = "</s"

def GetTheSentences(file):
    start_rx = re.compile(Del1)
    end_rx = re.compile(Del2)

    start = False
    output = []
    with file as datafile:
         for line in datafile.readlines():
             if re.match(start_rx, line):
                 start = True
             elif re.match(end_rx, line):
                 start = False
             if start:
                  output.append(line)
    return output
	
print (GetTheSentences(textfileread))
print (textfileread.readlines())

textfilewrite.close()
textfileread.close()