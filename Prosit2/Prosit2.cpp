#include "Liberary1.h"
#include "Liberary2.h"

int main()
{
	cout << "Crypter / D�crypter de fichier" << endl;

	Crypt crypt;
	File fileTool;
	string text;
	string txtACoder;
	string txtDecode;
	int decalage;
	char key;
	int mode = -1;
	int size;

	while (mode != 4) 
	{
		cout << " Mode de cryptage :\n 1 - Cesar\n 2 - XOR\n 3 - Cesar + XOR\n 4 - Quitter" << endl;
		cin >> mode;

		if (mode > 0 && mode < 4)
		{
			int modeCode = -1;
			while (modeCode < 1 or modeCode > 2)
			{
				cout << " Que souhaitez-vous ? :\n 1 - Crypter\n 2 - D�crypter" << endl;
				cin >> modeCode;
			}

			cout << "Entrez le chemin d'acc�s du fichier � crypter :" << endl;
			cin >> text;

			int inputMode = 0;
			cout << "Voulez-vous crypter � partir:\n1. Message saisi\n2. Fichier" << endl;
			cin >> inputMode;

			if (inputMode == 1)
			{
				cout << "Entrez le texte � crypter :" << endl;
				cin >> txtACoder;
			}

			if (mode == 1 or mode == 3)
			{
				cout << "Entrez le d�calage :" << endl;
				cin >> decalage;

				if (modeCode == 2)
				{
					decalage = -decalage;
				}

				if (mode == 1)
				{
					if (inputMode == 1)
					{
						txtDecode = crypt.cesar(txtACoder, decalage);
					}
					else
					{
						txtDecode = crypt.cesar(fileTool.readFile(text + ".txt"), decalage);
					}
					fileTool.writeFile(text + ".txt", txtDecode);
				}
			}

			if (mode == 2 or mode == 3)
			{
				cout << " Entrez la cl� de chiffrement : " << endl;
				cin >> key;
				if (modeCode == 2)
				{
					cout << " Entrez la taille du fichier: " << endl;
					cin >> size;

				}
				else
				{
					size = sizeof(txtACoder);
				}
				if (mode == 2)
				{
					if (inputMode == 1)
					{
						txtDecode = crypt.XOR(txtACoder, key);
					}
					else
					{
						txtDecode = crypt.XOR(fileTool.readFileBin(text + ".bin", size), key);
					}
					cout << txtDecode << endl;
					if (modeCode == 1)
					{
						fileTool.writeFileBin(text + ".bin", txtDecode, size);
					}
					else
					{
						fileTool.writeFile(text + ".txt", txtDecode);
					}
				}
			}
			if (mode == 3)
			{
				if (inputMode == 1)
				{
					txtDecode = crypt.cesarXXOR(txtACoder, decalage, key, modeCode);
				}
				else
				{
					txtDecode = crypt.cesarXXOR(fileTool.readFileBin(text + ".bin", size), decalage, key, modeCode);
				}

				if (modeCode == 1)
				{
					fileTool.writeFileBin(text + ".bin", txtDecode, size);
				}
				else
				{
					cout << "Texte d�cod�: " << txtDecode << endl;
					fileTool.writeFile(text + ".txt", txtDecode);
				}

			}
			cout << "Fichier " << text << " crypt� avec succ�s !" << endl;
		}
	}

}


