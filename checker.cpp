
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

double calculatSimilarity(const string& originalText, const string& plagiarizedText)
{
	int commonCount = 0;//����ԭ���볭Ϯ�ĵ�����ͬ�ַ���Ŀ
	int totalLength = originalText.length();//�õ�ԭ�ĵ��ַ�����

	for (char c : plagiarizedText)//������Ϯ�ģ���ԭ�����ҵ���ͬ�ַ�����Ŀ
	{
		if (originalText.find(c) != string::npos)
		{
			commonCount++;
			if (commonCount == totalLength)break;//���ظ��ַ�����ԭ�ĳ���ʱ����ʱ�������Ѿ���100%��
		}
	}
	return static_cast<double>(commonCount) / totalLength;
}

int main()
{
	//�ֱ�����ԭ�ĺͳ�Ϯ�ĵ�·��
	string originalFile = "D:/�ҵ��ĵ�/test/orig.txt";
	string plagiarzedFile = "D:/�ҵ��ĵ�/test/orig_0.8_del.txt";
	string outputFile = "D:/�ҵ��ĵ�/test/result.txt";

	ifstream originalStream(originalFile);
	ifstream plagiarizedStream(plagiarzedFile);
	ofstream outputStream(outputFile, std::ios::app);//����ļ������ھʹ���

	if (!originalStream || !plagiarizedStream || !outputStream)//�κ�һ���ļ���ʧ�ܶ�����1
	{
		cout << "Failed to open input or output file." << endl;
		return 1;
	}

	string originalText((istreambuf_iterator<char>(originalStream)), istreambuf_iterator<char>());//��ԭ���ж�ȡ�ַ��洢���ַ���originalText��
	string plagiarizedText((istreambuf_iterator<char>(plagiarizedStream)), istreambuf_iterator<char>());//�ӳ�Ϯ���ж�ȡ�ַ��洢���ַ���plagiarizedText��

	double similarity = calculatSimilarity(originalText, plagiarizedText);//�õ����

	outputStream << fixed << setprecision(2) << similarity << endl;//�����������ļ���

	originalStream.close();
	plagiarizedStream.close();
	outputStream.close();


	return 0;
}


