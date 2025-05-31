import serial
from message_parser import MessageParser
from device_handler import DeviceHandler

comPort = 'COM5' # Thay đổi theo cổng COM của bạn
_baudrate = 115200 # Thay đổi theo baudrate của bạn

if __name__ == "__main__":
    # Kết nối cổng COM (cấu hình đúng port và baudrate của bạn)
    ser = serial.Serial(port=comPort, baudrate=_baudrate, timeout=0.1)
    parser = MessageParser()
    handler = DeviceHandler()

    print("Listening for messages...")
    while True:
        if ser.in_waiting:
            line = ser.readline().decode('utf-8').strip()
            if line:
                print("Received:", line)
                action = parser.parse(line)
                if action:
                    handler.execute(action)

