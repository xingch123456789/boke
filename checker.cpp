
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

double calculatSimilarity(const string& originalText, const string& plagiarizedText)
{
	int commonCount = 0;//计算原文与抄袭文档的相同字符数目
	int totalLength = originalText.length();//得到原文的字符长度

	for (char c : plagiarizedText)//遍历抄袭文，在原文中找到相同字符的数目
	{
		if (originalText.find(c) != string::npos)
		{
			commonCount++;
			if (commonCount == totalLength)break;//当重复字符大于原文长度时，此时查重率已经是100%了
		}
	}
	return static_cast<double>(commonCount) / totalLength;
}

int main()
{
	//分别输入原文和抄袭文的路径
	string originalFile = "D:/我的文档/test/orig.txt";
	string plagiarzedFile = "D:/我的文档/test/orig_0.8_del.txt";
	string outputFile = "D:/我的文档/test/result.txt";

	ifstream originalStream(originalFile);
	ifstream plagiarizedStream(plagiarzedFile);
	ofstream outputStream(outputFile, std::ios::app);//如果文件不存在就创建

	if (!originalStream || !plagiarizedStream || !outputStream)//任何一个文件打开失败都返回1
	{
		cout << "Failed to open input or output file." << endl;
		return 1;
	}

	string originalText((istreambuf_iterator<char>(originalStream)), istreambuf_iterator<char>());//从原文中读取字符存储到字符串originalText中
	string plagiarizedText((istreambuf_iterator<char>(plagiarizedStream)), istreambuf_iterator<char>());//从抄袭文中读取字符存储到字符串plagiarizedText中

	double similarity = calculatSimilarity(originalText, plagiarizedText);//得到结果

	outputStream << fixed << setprecision(2) << similarity << endl;//将结果输出到文件中

	originalStream.close();
	plagiarizedStream.close();
	outputStream.close();


	return 0;
}


