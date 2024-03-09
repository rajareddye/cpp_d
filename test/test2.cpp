#include <boost/filesystem.hpp>  
#include <iostream>  
  
int main()  
{  
     
boost::filesystem::path path_to_dir("/home/rre/cpp/");  
  
    if (boost::filesystem::exists(path_to_dir) && boost::filesystem::is_directory(path_to_dir))  
    {  
        for (boost::filesystem::directory_entry& entry : boost::filesystem::directory_iterator(path_to_dir))  
        {  
            if (boost::filesystem::is_regular_file(entry.path()))  
            {  
                 
std::cout << entry.path().filename() << std::endl;  
            }  
        }  
    }  
    else  
    {  
        std::cout << "Directory does not exist or is not a directory." << std::endl;  
    }  
  
    return 0;  
}  