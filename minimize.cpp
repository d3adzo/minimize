#include <iostream>
#include <fstream>
#include <Shldisp.h>
#include <chrono>
#include <thread>

#define MIN_ALL 419

int main()
{
    int ctr = 0;
    char num_char[5];
    while (TRUE) 
    {
        // convert int to char array
        std::sprintf(num_char, "%d", ctr);

        // minimize
        HWND lHwnd = FindWindow(L"Shell_TrayWnd", NULL);
        SendMessage(lHwnd, WM_COMMAND, MIN_ALL, 0);

        // write to file
        std::ofstream fs("c:\\minimize.txt", std::ios_base::app);

        if (!fs)
        {
            std::cerr << "Cannot open the output file." << std::endl;
            return 1;
        }
        fs << "d3adzo minimized all your windows ;) -> Iteration #" << num_char << "\n";
        fs.close();
        
        ctr++;

        // sleep thread
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
    return 0;
}

