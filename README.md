This project is designed to get around using the Arudino UNO Mouse library. In my experience, the Arudino can't control the mouse and maintain a connection to the computer at the same time.
Instead, this project reads a joystick and sends information about the direction though a serial port.
Python then reads that serial information and adjusts the mouse accordingly
