from action_map import MouseClick, MouseHold, MouseRelease

class MessageParser:
    def __init__(self):
        self.mapping = {
            "LMClick": MouseClick("left"),
            "LMHold": MouseHold("left"),
            "LMRel": MouseRelease("left")
        }

    def parse(self, message: str):
        return self.mapping.get(message, None)
