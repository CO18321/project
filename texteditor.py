#importing all necessary modules

from tkinter import *
from sys import *
from tkinter.messagebox import showerror
from tkinter import messagebox
from tkinter.filedialog import asksaveasfile,askopenfile,askopenfilename
from tkinter import colorchooser
from tkinter.ttk import Combobox
from tkinter import simpledialog


#global variables
f=None
text= None 
root=None
top=None
w=None


#for seting the title of window
def set_w_title(name):
	global root
	if name:
		root.title(name)
	else:
		root.title("untitled ")


#for opening new window
def newfile(*args):
	main()


#for saving changes files
def savefile(*args):
	global f
	
	if f:
		try:
			t=text.get(0.0,END)
			#size_a=getsizeof(t)
			with open(f,"a") as file:
				file.truncate(0)
				file.write(t)
				#size_a=getsizeof(file)
		except Exception as e:
			print(e)


#for saving file on specific location
def saveas(*args):
	global f
	f=asksaveasfile(initialfile="Untitled.txt",mode='w',defaultextension='.txt')
	t=text.get(0.0,END)
	try:
		f.write(t.rstrip())
	except Exception as e:
		print(e)
		showerror(title="OOPS!",message="unable to save file")


#for opening a file and inserting its content in editor
def openfile(*args):
	global f
	f=askopenfilename(defaultextension='.txt',filetypes=[("All files","*.*"),("text files","*.txt*"),\
		("python scripts","*.py*")])
	if f:
		text.delete(0.0,END)
		with open(f,"r+") as fn:
			text.insert(0.0,fn.read())
			
	set_w_title(f)
	

#for about window
def about():
	print("about called")

	bt="ABOUT"
	bm="This Text editor is created by Ganga Singh,Ishit Kanwar and Kanish Chauhan \
	 (1st-year CSE)\n \nit is made by using python programming language";
	messagebox.showinfo(bt,bm)


#to copy text under selected area	
def copy(*args):
	global text
	text.clipboard_clear()
	text.clipboard_append(text.selection_get())


#to cut text under selected area
def cut(*args):
	copy()
	text.delete("sel.first","sel.last")

#to paste content which was copied or cuted
def paste(*args):
	text.insert(INSERT,text.clipboard_get())


#to append color of background
def colorsch():
	global root,text
	clr=colorchooser.askcolor(title="Select Background Color")
	print(clr[1])
	text.config(bg=clr[1])


#to append font color
def fontcolor():
	global text
	clr=colorchooser.askcolor(title="Select Font Color")
	text.config(fg=clr[1])


def getsize():
	global w,text
	ct=w.get()
	print(ct)
	text.config(font=(None,ct))
	top.destroy()


#to append font size
def size():
	global top, w
	top = Tk() 
	top.geometry("400x400+100+100")
	top.resizable(0,0)
	top.title("Select Font Size")

	v=list(range(1,200))

	w = Combobox(top,values=v,width=30,height=22) 
	w.set("8")
	w.pack(fill=BOTH) 

	button=Button(top,text="OK",activeforeground="lightblue",command=getsize)
	button.pack(side=BOTTOM,fill=BOTH)
	top.mainloop() 


def getstyle():
	global w,text
	ct=w.get()
	print(ct)
	text.config(font=(ct,0))
	top.destroy()


#to append style of font
def style():
	global top, w
	fs=['Agency FB',"Arial",'Baskerville Old Face',"Bell MT","Calibri",'Candra',"Century Schoolbook",'Comic Sans MS','Ebrima',\
	"Elephant",'ENGRAVERS','Forte','Franklin Gothic Book','Franklin Gothic Demi','Georgia','Gadugi','Gigi',\
	'Goudy Old Style','Harrington','High Tower Text','Ink Free','Jokerman','Lucida Calligraphy','Lucida Fax','Lucida Sans',\
	'Microsoft YaHei UI','Monotype Corsiva'\
	'Nirmala UI','Palatino Linotype','Papyrus','Perpetua','Poor Richard','Rockwell','Rockwell Condensed'\
	'Script MJ Bold','Segoe Print','segoe Script','Segoe UI','segoe UI Black','SHOWCARD GOTHIC','Sitka Text',\
	'Tahoma','Times New Roman','Verdana']
	
	top = Tk() 
	top.geometry("400x400+100+100")
	top.resizable(0,0)
	top.title("Select Font Style")

	#label=Label(top,text="select size ").pack()
	w = Combobox(top,values=fs,width=30,height=22) 
	w.set("Calibri")
	w.pack(fill=BOTH) 

	button=Button(top,text="OK",activeforeground="lightblue",command=getstyle)
	button.pack(side=BOTTOM,fill=BOTH)
	top.mainloop() 
	

#main 
def main():
	global root
	root=Tk()
	bs=' '

	root.title(set_w_title(None))
	root.geometry("900x500+80+80")

	fonts=("Calibri",15)
	global text
	text=Text(root,font=fonts,undo=True,wrap=WORD,padx=2,pady=2,bd=2)#,width=500,height=500)
	
	scroll=Scrollbar(root,command=text.yview)
	text.configure(yscrollcommand=scroll.set)
	text.pack(side=LEFT,fill=BOTH,expand=True)
	scroll.pack(side=RIGHT,fill=Y)

	menubar=Menu(root)
	filemenu=Menu(menubar,tearoff=0)
	filemenu.add_command(label="New File            ",accelerator="Ctrl+N",command=newfile)
	filemenu.add_command(label="Open",accelerator="Ctrl+O",command=openfile)
	filemenu.add_command(label="Save",accelerator="Ctrl+S",command=savefile)
	filemenu.add_command(label="Save As...",accelerator="Ctrl+Shift+S",command=saveas)
	filemenu.add_separator()

	filemenu.add_command(label="Exit",command=root.destroy)
	menubar.add_cascade(label='File',menu=filemenu)


	#for binding keyboard shortcuts with functions 
	text.bind("<Control-n>",newfile)
	text.bind("<Control-o>",openfile)
	text.bind("<Control-s>",savefile)
	text.bind("<Control-S>",saveas)


	editmenu = Menu(menubar,tearoff=0) 
	menubar.add_cascade(label='Edit', menu=editmenu) 
	
	editmenu.add_command(label='Undo           ',accelerator="Ctrl+Z",command=text.edit_undo) 
	editmenu.add_command(label="Redo",accelerator="Ctrl+Y",command=text.edit_redo)
	editmenu.add_separator()
	
	editmenu.add_command(label="Cut",accelerator="Ctrl+X",command=cut)
	editmenu.add_command(label="Copy",accelerator="Ctrl+C",command=copy)
	editmenu.add_command(label="Paste",accelerator="Ctrl+V",command=paste)


	pref = Menu(menubar,tearoff=0) 
	menubar.add_cascade(label='Preferences', menu=pref) 
	pref.add_command(label="Background Scheme...",command= colorsch)
	#pref.add_command(label="font")

	fontm=Menu(pref,tearoff=0)
	fontm.add_command(label="Color",command=fontcolor)
	fontm.add_command(label="Size",command=size)
	fontm.add_command(label="Style",command=style)
	pref.add_cascade(label="Font ",menu=fontm)

#	pref.add_command(label="Size",accelerator="Ctrl+V",command=paste)
	
	helpmenu = Menu(menubar,tearoff=0) 
	menubar.add_cascade(label='Help', menu=helpmenu) 
	helpmenu.add_command(label='About GIK-TextEditor',command=about) 


	root.config(menu=menubar)
	root.mainloop()

if __name__ == '__main__':
	main()

