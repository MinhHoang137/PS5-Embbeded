# PS5ControllerEmulator 
🖱️ Hướng dẫn sử dụng – Mô phỏng nút chuột trái bằng STM32
🛠️ Yêu cầu phần cứng
1 board STM32 có hỗ trợ UART (ví dụ: STM32F103, STM32F4xx)

1 nút nhấn (kết nối với chân GPIO)

Cáp USB để kết nối STM32 với máy tính

Mạch chuyển UART–USB (nếu STM32 không hỗ trợ trực tiếp USB CDC)

⚙️ Cài đặt phần mềm
1. Trên STM32
Flash firmware trong thư mục STM32_Firmware/ vào board.
Trong code, nút nhấn đang được gán mặc định vào chân PA0.
Khi bạn nhấn, giữ, hoặc nhả nút này, STM32 sẽ gửi các chuỗi sau qua UART:
"LMClick": Nhấn nút ngắn
"LMHold": Giữ nút lâu
"LMRel": Thả nút sau khi giữ
Lưu ý: thời gian "giữ lâu" được định nghĩa là 0.3 giây (tương đương minHoldTime = 3000 đơn vị 0.1 ms)

2. Trên máy tính
Cài Python 3.8+ và các thư viện cần thiết:
pip install pyserial pyautogui

Chạy script Python:
python main.py

Script sẽ:
Nghe tín hiệu UART tại cổng COM bạn đã khai báo
Khi nhận được "LMClick" → mô phỏng click chuột trái
Khi nhận được "LMHold" → mô phỏng giữ chuột trái
Khi nhận được "LMRel" → mô phỏng thả chuột trái

💡 Mô tả hành vi
Khi nhấn nút nối với chân PA0, STM32 bắt đầu đếm thời gian giữ nút.

Nếu nhấn rồi thả nhanh (dưới 300ms), STM32 gửi chuỗi "LMClick" qua UART để mô phỏng nhấp chuột trái.

Nếu giữ lâu hơn 300ms, chuỗi "LMHold" được gửi để mô phỏng giữ chuột trái.

Khi thả nút sau khi giữ, chuỗi "LMRel" được gửi để mô phỏng thả chuột trái.

Máy tính nhận các chuỗi này qua UART, phần mềm Python xử lý và thực hiện hành động chuột tương ứng.


🧪 Kiểm tra hoạt động
Mở một phần mềm như Paint, giữ nút vật lý trên STM32 → kiểm tra chuột có kéo không.

Xem console Python để xác nhận có nhận được đúng chuỗi UART.

🔧 Gỡ lỗi
Nếu không nhận được tín hiệu UART:

Kiểm tra đúng cổng COM trong main.py

Kiểm tra baudrate đúng với STM32 (thường là 115200)

Nếu Python báo lỗi không mở được COM:

Đảm bảo thiết bị không bị ứng dụng khác chiếm dụng (ví dụ: TeraTerm, PuTTY)

📍 Mục tiêu tiếp theo
Mở rộng để điều khiển nhiều nút khác như chuột phải, phím bàn phím, joystick

Tích hợp với game engine Unity hoặc game thực tế
