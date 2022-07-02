#!/usr/bin/env python
#coding: utf8

import time, datetime
import telepot
from telepot.loop import MessageLoop

#import os
#import RPi.GPIO as GPIO

#now = datetime.datetime.now()



#def action(msg):
 #   chat_id = msg['chat']['id']
 #   command = msg['text']

 #   print 'Received: %s' % command

 #   if command == '/hi':
  #      telegram_bot.sendMessage (1675750958, str("Hallo"))
 #   elif command == '/time':
  #      telegram_bot.sendMessage(1675750958, str(now.hour)+str(":")+str(now.minute))

telegram_bot = telepot.Bot('1775198416:AAE6wzVNjaGbAbL5EiINnSEW5mE6z4PPBEQ')
#print (telegram_bot.getMe())

#MessageLoop(telegram_bot, action).run_as_thread()
#print 'Up and Running....'

telegram_bot.sendMessage (1675750958, str("Es hat geklingelt!!"))

# Keep the program running.
#while 1:
   # time.sleep(10)
