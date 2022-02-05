import sys

def cifWord(word):
  text = word
  result = 0
  
  for a in text:
    num = ord(a) - ord('A') + 1
    result += num
    print(a, ': ', num)
  
  print('sum: ', result)
  
  step = 0
  while result >= 10:
    step += 1
    text = str(result)
    result = 0
    for a in text:
      num = ord(a) - ord('0')
      result += num
    print(str(step) + '. step: ', result)
  
  print('final: ', result)
  return result

##########################################################

if len(sys.argv) != 2:
  print('Argument error!')
  exit(-1);

inputString = sys.argv[1]
inputString = inputString.split()
key = ""

for a in inputString:
  key += str(cifWord(a))

print('KEY: ', key)

