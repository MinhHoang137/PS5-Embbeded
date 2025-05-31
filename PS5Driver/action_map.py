from pynput.mouse import Button, Controller

mouse = Controller()

class Action:
    def execute(self):
        pass

class MouseClick(Action):
    def __init__(self, button: str):
        self.button = Button.left if button == "left" else Button.right

    def execute(self):
        mouse.click(self.button)

class MouseHold(Action):
    def __init__(self, button: str):
        self.button = Button.left if button == "left" else Button.right

    def execute(self):
        mouse.press(self.button)

class MouseRelease(Action):
    def __init__(self, button: str):
        self.button = Button.left if button == "left" else Button.right

    def execute(self):
        mouse.release(self.button)
