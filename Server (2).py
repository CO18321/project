from tkinter import *
import threading
import time
import socket
import sys
from tkinter import messagebox
from tkinter.messagebox import showerror,askretrycancel

from datetime import datetime

e=None
root=None
s=None
f=None

def viewhistory(*args):
    global f
    top=Tk()
    top.title(" YOUR CHATTING HISTORY")
    top.geometry("500x500+5+5")
    f=open("C:\\Users\\Gopal singh\\Desktop\\sublime py files\\sh.txt",'r')
    text=Text(top,font=("century schoolbook",10),wrap=WORD,padx=2,pady=2,bd=2)
    
    scroll=Scrollbar(top,command=text.yview)
    text.configure(yscrollcommand=scroll.set)
    text.pack(side=LEFT,fill=BOTH,expand=True)
    scroll.pack(side=RIGHT,fill=Y)
    text.delete(0.0,END)
    text.insert(0.0,f.read())
    top.mainloop()


def clearhistory(*args):

    answer=messagebox.askyesnocancel(" Delete History  ","Are you sure you want to permanently clear your chat history?")
    if answer==True:
        f=open("C:\\Users\\Gopal singh\\Desktop\\sublime py files\\sh.txt",'w')
        f.truncate(0)
    else:
        pass
        

def cr():
    global e,conn,s
    host=''
    port=9999

    s=socket.socket()
    #print("binding the port:"+str(port))
    s.bind((host,port))
    s.listen(5)
    conn,address = s.accept()
    while True:
        if str(conn.recv(1024)):
            client_response=str(conn.recv(1024),'utf-8')
            gunc(client_response)
            print("client:"+client_response,end='')
        else:
            pass

lst=[]
x=0

def func(msg):
    global root,lst,x,e,f
    if x<8:

        f=open("C:\\Users\\Gopal singh\\Desktop\\sublime py files\\sh.txt",'r+')
        f.read()
       
        mess=Message(root,text=msg,bg='lightblue',justify='right',pady=5,padx=5,relief=GROOVE,anchor=E,aspect=1200)
        mess.config(font=("Century Schoolbook",15))
        lst.insert(x,mess)
        mess.pack(fill=X)
        f.write("\nyou:     ")
        f.write(msg)
       # f.write("\n")
        f.close()
        x+=1

    else:
        for i in range(0,8):
            lst[i].destroy()
        x=0
        func(msg)

def gunc(msg):
    global root,lst,x,f
    if x<8:
        
        f=open("C:\\Users\\Gopal singh\\Desktop\\sublime py files\\sh.txt",'r+')
        f.read()
        
        mess=Message(root,text=msg,bg='lightgrey',justify='right',pady=5,padx=5,relief=GROOVE,anchor=W,aspect=1200)
        mess.config(font=("Century Schoolbook",15))
        mess.pack(fill=X)
        lst.insert(x,mess)
        f.write("\nclient:  ")
        f.write(msg)
     #   f.write("\n")
        f.close()
        x+=1

    else:
        for i in range(0,8):
            lst[i].destroy()
        x=0
        gunc(msg)



def main():
    global e,root,s,f
    root=Tk()
    root.geometry("600x600+2+2")
    root.resizable(0,0)
    root.title('server')
    

    bkgt= PhotoImage(file=r"C:\Users\Gopal singh\Desktop\sublime py files\bkg1.gif")
    bkg=bkgt.subsample(2,2)

    b=Label(root,image=bkg)
    b.place(x=0,y=0)

    photo = PhotoImage(file=r"C:\Users\Gopal singh\Desktop\sublime py files\download1gif.gif")
    pimg=photo.subsample(6,7)

    button = Button(root ,image=pimg,command=thread) 
    button.pack(side=RIGHT,anchor=SE) 

    e=Entry(root,width=60,font=("century schoolbook",15))
    e.pack(side=BOTTOM,anchor=SW,ipady=10,ipadx=4)
    e.bind("<Return>",server)
    e.bind("<Control-h>",viewhistory)
    e.bind("<Control-H>",clearhistory)

    menubar=Menu(root)
    historymenu=Menu(menubar,tearoff=0)
    historymenu.add_command(label="View",command=viewhistory)
    historymenu.add_command(label="Clear",command=clearhistory)

    menubar.add_cascade(label='Chat History',menu=historymenu)
    root.config(menu=menubar)
    f=open("C:\\Users\\Gopal singh\\Desktop\\sublime py files\\sh.txt",'r+')
    f.read()
    x=str(datetime.now())
    print(x)
    f.write("\n\n\t\t--------")
    f.write(x)
    f.write("--------\n\n")
    f.close()


    thread2()    
    ter=threading.Thread(target=root.mainloop())    
    ter.daemon=True
    ter.start()

#
#
#
conn=None

def server(*args):
    global conn ,e,root
    print("\n")
    msg=e.get()#input("you:
    e.delete(0,END)
    if sys.getsizeof(msg)>25:
    #len(str.encode(msg))>0 &&: 
        try:
           
            conn.send(str.encode(msg))
            func(msg)
            time.sleep(0.1)
            conn.send(str.encode(msg))
            print("\n")
        except:
            ans=askretrycancel("OOPS","Client is not connected!")
            if ans==True:
                server()
            else:
                root.quit()


def thread2():
    t=threading.Thread(target=cr)

    t.daemon=True
    t.start()
    #thread2()


def thread():
    #thread2() 
    t=threading.Thread(target=server)
    #thread2()

    t.daemon=True
    t.start()
#main()
main()
#thread2()