from docx.text.paragraph import Paragraph
from docx import Document

L = list(range(73, 383))
for i in L[:]:
    fromname = "./from/" + str(i) + ".docx"
    toname = "./to/" + str(i) + ".txt"

    document = Document(fromname)
    to = open(toname, 'w')
    for p in document.paragraphs:
        tempPara = p.text + '\n'
        to.write(tempPara)
    to.close()