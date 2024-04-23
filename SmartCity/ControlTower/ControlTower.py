import sys
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5 import uic
import mysql.connector

from_class = uic.loadUiType("ControlTower.ui")[0]

class WindowClass(QMainWindow, from_class):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.setWindowTitle("Control Tower")
        
        self.conn = self.connection()
        self.rcvLocation()

    def connection(self):
        conn = mysql.connector.connect(
            host = "smartcity.cdv9nppqt3kw.ap-northeast-2.rds.amazonaws.com",
            user = "dev",
            port = 3306,
            password = "0423",
            database = "SmartCity"
        )
        return conn


    def rcvLocation(self):
        cur = self.conn.cursor(buffered=True)
        cur.execute("SELECT 위치 FROM TestDB")
        
        result = cur.fetchone()
        result = result[0]
        
        self.conn.close()
        # 버스 위치 받아오는 함수 작성
        self.busEdit.setText("")
        # 쓰레기 수거 차량 위치 받아오는 함수 작성
        self.gtEdit.setText("")

    def rcvLight(self):
        # 적색 신호등 상태 받아오는 함수 작성
        self.redBtn.setChecked(True)
        self.redBtn.setChecked(False)
        # 황색 신호등 상태 받아오는 함수 작성
        self.yellowBtn.setChecked(True)
        self.yellowBtn.setChecked(False)
        # 녹색 신호등 상태 받아오는 함수 작성
        self.greenBtn.setChecked(True)
        self.greenBtn.setChecked(False)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    myWindows = WindowClass()
    myWindows.show()

    sys.exit(app.exec_())