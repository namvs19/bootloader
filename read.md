bootloader nhận dữ liệu từ PC định dạng srec

chương trình bootloader và app cần nằm trong flash
-> phần vùng cho flash: cho bootloader và app

impossible: sửa file binary nhận được để ghi vào phân vùng mong muốn mặc dù file binary được tạo ra để nạp vào vùng bắt đầu của flash
Người dùng cần biết vùng địa chỉ của app để cấu hình linker build chương trình ra vào đúng vùng mà bootloader chuẩn bị
-> tìm hiểu cách sửa linker

    các thành phần trong flash của app:
        text/code
            hàm phục vụ ngắt
        const
        initializer (khởi tạo cho data)
        startup code
        vector table
    chương trình app cần chạy ở vector table nằm ở địa chỉ khác vector table của bootloader (0xA000)


BTVN: tìm hiểu cách sửa linker để build chương trình vào địa chỉ mong muốn, cách sửa vector table (VTOR)

Next milestone:
Học cách ghi flash
Xử lí srec
Thuật toán queue

Báo lỗi cho người dùng: chính xác
Thời gian nạp firmware phải nhanh:
ghi flash nhanh
check lỗi nhanh
hỗ trợ baurate cao: 115200
Độ chính xác cao (tỉ lệ xảy ra lỗi thấp)
Hỗ trợ nạp lại firmware nếu có lỗi
Có lỗi nạp lại từ đầu
lỗi đang nạp mà mất điện: cố gắng xử lí

user interface để lựa chọn chạy app cũ hay nạp app mới
không delay việc vào app
nhấn sw1 khi khởi động để vào nạp firmware mới

    check lỗi srec
    check lỗi parity
        Srec gần như bao gồm được parity -> có value lớn
        Parity check bởi phần cứng, phần mềm ko cần can thiệp -> free
