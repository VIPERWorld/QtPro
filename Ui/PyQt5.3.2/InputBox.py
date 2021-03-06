from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *

class InputBox(QLineEdit):
    def __init__(self):
        super(InputBox, self).__init__()
        self.setAlignment(Qt.AlignCenter)
        self.setMinimumHeight(30)
        font=QFont()
        font.setFamily('boto Condensed')
        font.setPointSize(12)
        self.setFont(font)
        self.setStyleSheet("background-color: #e9e9e9;border-radius:3px;")
        self.setPlaceholderText('Input bx')

    def get_border(self):
        return Qt.black

    def set_border(self, Color):
        self.setStyleSheet(" border : 1.5px solid rgb({0}, {1}, {2});"
                           "border-radius:3px;"
                           .format(Color.red(), Color.green(), Color.blue()))

    border=QtCore.pyqtProperty(QColor, get_border, set_border)

    def focusInEvent(self, event):
        global anim
        anim=QPropertyAnimation(self, "border")
        anim.setStartValue(QColor("#FFFFFF"))
        anim.setEndValue(QColor("#82CDF8"))
        anim.setDuration(230)
        anim.start()
        self.setStyleSheet('background:white;border:none;border-radius:3px;')
        QLineEdit.focusInEvent(self, event)

    def focusOutEvent(self, event):
        self.setStyleSheet('background:#e9e9e9;border:none;border-radius:3px;')
        QLineEdit.focusOutEvent(self, event)
