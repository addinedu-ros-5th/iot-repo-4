import sys
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5 import uic
import serial

from_class = uic.loadUiType("src/ControlTower.ui")[0]

class WindowClass(QMainWindow, from_class):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.setWindowTitle("Control Tower")
        
        self.conn = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=1)

        self.aptBtn.clicked.connect(lambda: self.sendData(b'3'))
        self.parkBtn.clicked.connect(lambda: self.sendData(b'2'))
        self.schoolBtn.clicked.connect(lambda: self.sendData(b'4'))
        self.stationBtn.clicked.connect(lambda: self.sendData(b'1'))
        
    def sendData(self, data):
        self.conn.write(data)
    

if __name__ == "__main__":
    app = QApplication(sys.argv)
    myWindows = WindowClass()
    myWindows.show()

    sys.exit(app.exec_())