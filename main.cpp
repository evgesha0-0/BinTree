#include <iostream>
#include "tree.cpp"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	Tree<double>* TTree = new Tree<double>(1.2);
	TTree->InsertLeft(2.3);
	TTree->InsertRight(3.7);
	TTree->GetLeft()->InsertLeft(4.3);
	TTree->GetLeft()->InsertRight(7.8);
	TTree->GetRight()->InsertLeft(9.7);
	TTree->GetRight()->InsertRight(5.6);

	cout << "Горизонтальный вывод дерева: " << endl;
	TTree->PrintTree(1);
	cout << endl << endl;

	double key = 0;
	cout << "Введите ключ для поиска элемента: ";
	cin >> key;
	if (TTree->Search(key))
	{
		cout << "Элемент " << key << " найден." << endl;
	}
	else
	{
		cout << "Такого элемента нет." << endl;
	}
	cout << endl << endl;

	cout << "Вертикальный вывод дерева:" << endl;
	TTree->PrintVTree();
	cout << endl << endl;

	cout << "Прямой обход дерева:" << endl;
	TTree->ReOrder(TTree);
	cout << endl << endl;

	cout << "Симметричный обход дерева:" << endl;
	TTree->InOrder(TTree);
	cout << endl << endl;

	cout << "Обратный обход дерева:" << endl;
	TTree->PostOrder(TTree);
	cout << endl << endl;

	double sum = TTree->LevelScan();
	int l = TTree->GetAmounthOfNodes();
	double arithmetic = sum / l;
	cout << "Среднее арифметическое число элементов дерева: " << arithmetic << endl << endl;

	Tree<double>* TTree_Ball = new Tree<double>(1.8);
	int n;
	cout << "Введите количество элементов для сбалансированного дерева: ";
	cin >> n;

	Tree<double>* TTree_Balans = TTree_Ball->BalancedTree(n);
	cout << endl;

	cout << "Горизонтальный вывод сбалансированного дерева:" << endl;
	TTree_Balans->PrintTree(1);
	cout << endl << endl;

	cout << "Вертикальный вывод сбалансированного дерева:" << endl;
	TTree_Balans->PrintVTree();
	cout << endl << endl;

	cout << "Преобразуем дерево, в дерево поиска: " << endl;
	TTree_Balans->CreateBalans(TTree_Balans);

	cout << "Горизонтальный вывод дерева поиска:" << endl;
	TTree_Balans->PrintTree(1);
	cout << endl << endl;

	cout << "Вертикальный вывод дерева поиска:" << endl;
	TTree_Balans->PrintVTree();
	cout << endl << endl;

	return 0;
}
