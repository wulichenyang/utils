
L = list(range(73, 383))
for i in L[:]:
  toname = "./to/" + str(i) + ".txt"
  utf = "./utf/" + str(i) + ".txt"

  fin = open(toname, 'r')
  fout = open(utf, 'wb')

  # data = fin.read()
  # fout.write(data.encode('utf-8'))
  row = len(list(fin))
  fin.seek(0, 0)
  while row:
      line = fin.readline() 
      # 这里可以进行逻辑处理
      temp = line + '\r\n'
      if row == 1:
          temp = temp[:-3]
      fout.write(temp.encode('utf-8'))
      row -= 1

  fin.close()
  fout.close()