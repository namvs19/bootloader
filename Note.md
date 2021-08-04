Mock project: Xây dựng chương trình bootloader nạp chương trình cho vdk
nhận vào file SREC từ PC thông qua UART.

Yêu cầu: - Phát hiện lỗi srec - Cho phép nạp lại khi gặp lỗi - Báo lỗi

Nhiệm vụ

1. Nhận file srec qua UART
2. Kiểm tra file srec hợp lệ
3. Ghi nội dung chứa trong srec vào flash
4. Tự động chuyển sang chương trình application
   1. Quá trình nạp hoàn tất
   2. Khi không lựa chọn vào chế độ boot 
5. Sao lưu chương trình khi nạp mới chương trình.
6. Phục hồi chương trình cũ khi quá trình nạp lỗi.
7. Báo lỗi khi gặp lỗi.

Feature 7. Gặp lỗi không cần reset.

Đã có chương trình
Run mode - chạy application
Bootmode - backup - chuyển sang boot - nạp chuowgn trình - chạy application
Chưa có chương trình (- mới chưa nạp bao giờ, lần ghi trước bị lỗi)
Run mode
Có backup - Ghi lại backup memrory vào vùng nhớ app - chạy application
ko có backup - chuyển sang bootmode
Boot mode - nạp chuwogn trình - chạy application

Run mode
có chương trình - thực thi chuowgn trình
ko có chương trình - sang bootmode
Boot mode

### Presentation

1. Demo /** Nam */
2. Lên ý tưởng
   - Bài toán
     - Yêu cầu: Ts lại viết chương trình này?
     - Chương trình này sẽ làm gì?
       - Điều hướng sang application
       - Nạp mới chương trình
       - Sao lưu chương trình
       - Phục hồi chương trình
   - Phân tích bài toán
     - Nạp mới chương trình (core).
       - Nhận file nào?
       - Bằng cách nào?
       - đánh giá file
       - ...
     - Các lỗi cần xử lý
       - file nạp bị lỗi.
       - Lỗi mất đường truyền.
       - Lỗi mất điện.
       - Lỗi về giao thức truyền nhận.
     - Yêu cầu:
       - Độ chính xác cao.
       - Tốc độ nạp nhanh.
       - Gặp lỗi không cần reset vẫn có thể nạp lại.
       - Giao diện người (User interface)
         - Lựa chọn chế độ hoạt động
         - Báo lỗi/ trạng thái.
3. Phương pháp/ cách giải quyết

    /** Ninh */
   - Chương trình tổ chức theo kiến trúc startup

   - Điều hướng sang application
     - Nếu k bấm sw1 và ktra có reset handler thì chạy app.
   - Nạp mới chương trình
     - Sơ đồ khối tổng thể!
     - Chi tiết
       - Nhận UART
       - Xử lý SREC
       - Ghi vào Flash ntn
       - Xử lý khi lỗi diễn ra

    /** Nam */
   - Sao lưu chương trình
   - Phục hồi chương trình

4. Hướng phát triển
