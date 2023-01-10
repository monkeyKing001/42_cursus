#include <iostream>
#include <fstream>
int	main(int argc, char **argv)
{
	std::ifstream ifs;
	std::ofstream ofs;
	std::string input_file_path;
	std::string s1;
	std::string s2;
	std::string output_file_path;
	std::string contents;

	//argc check
	if (argc != 4)
	{
		std::cout << "Invalid arguments number\n";
		return (1);
	}
	input_file_path = argv[1];
	s1 = argv[2];
	s2 = argv[3];

	//replace argment check
	if (s1.length() == 0 || s2.length() == 0)
	{
		std::cout << "Invalid arguments path or name\n";
		return (1);
	}
	//input file open 
	ifs.open(input_file_path);
	//can't manipulate iput_file
	if (!ifs.good())
	{
		std::cout << "Failed to open input file. check the file name or path\n";
		return (1);
	}
	//output file open 
	output_file_path = input_file_path + ".replace";
	ofs.open(output_file_path);
	if (!ofs.good())
	{
		std::cout << "Failed to open output file. check the file name or path\n";
		return (1);
	}

	//for all contents
	while (true)
	{
		std::getline(ifs, contents);
		size_t pos = 0;
		//for one line
		while ((pos = contents.find(s1, pos)) != std::string::npos)
		{
			contents.erase(pos, s1.length());
			contents.insert(pos, s2);
			pos += s2.length();
		}
		ofs << contents;
		if (ifs.eof())
			break;
		ofs << std::endl;
	}
	//close file stream
	ifs.close();
	ofs.close();
	return (0);
}
