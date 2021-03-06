from PyQt4.QtGui import *
from PyQt4.QtCore import *
from PyQt4 import QtCore
from SaveButton import *

class CancelButton(SaveButton):
    def __init__(self):
        super(CancelButton, self).__init__()
        self.setStyleSheet("border:none;color: #868686;")
        self.setText('Cancel')

    def set(self, color):
        self.setStyleSheet("background-color: rgb({0}, {1}, {2});"
                           "color: #868686 ;"
                           "border-radius: 6px;".format(color.red(), color.green(), color.blue()))

    def get(self):
        return Qt.black

    color0=QtCore.pyqtProperty(QColor, get, set)

    def enterEvent(self, event):
        self.color_anim=QPropertyAnimation(self, "color")
        self.color_anim.setDuration(200)
        self.color_anim.setStartValue(QColor("#FFFFFF"))
        self.color_anim.setEndValue(QColor("#EDF7FF"))
        self.color_anim.start()

    def leaveEvent(self, event):
        self.color_anim=QPropertyAnimation(self, "color0")
        self.color_anim.setDuration(200)
        self.color_anim.setStartValue(QColor("#EDF7FF"))
        self.color_anim.setEndValue(QColor("#FFFFFF"))
        self.color_anim.start()
