#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
typedef struct data{
	string nama;
	string posisi;
	int no;
}dData;
class simpul
{
	public :
		dData datapemain;
		simpul* pBerikutnya;
		simpul(string n,string p, int np)
		{
			datapemain.nama = n;
			datapemain.posisi = p;
			datapemain.no = np;
			pBerikutnya = NULL;
		}
		void tampilSimpul()
		{
			cout << datapemain.no << "--->" << datapemain.nama << "--->" << datapemain.posisi<<endl;
		}
};
class linkedlist
{
	private :
		simpul* pPertama;
	public :
		linkedlist() : pPertama(NULL)
		{}
		~linkedlist()
		{
			simpul* pSekarang = pPertama;
			while(pSekarang!=NULL)
			{
				simpul* pLama = pSekarang;
				pSekarang = pSekarang->pBerikutnya;
				delete pLama;
			}
		}
		bool apaKosong()
		{
			return (pPertama==NULL);
		}
		void sisipPertama(string nP, string pP, int np)
		{
			simpul* pSimpulBaru = new simpul(nP,pP,np);
			pSimpulBaru->pBerikutnya = pPertama;
			pPertama = pSimpulBaru;
		}
		void hapusPertama()
		{
			simpul* pTemp = pPertama;
			pPertama = pPertama->pBerikutnya;
			delete pTemp;
		}
		void tampilSenarai()
		{
			simpul* pSekarang = pPertama;
			if(pSekarang==NULL)
			{
				cout << "STACK KOSONG!!!";
			}
			while(pSekarang!=NULL)
			{
				pSekarang->tampilSimpul();
				pSekarang = pSekarang->pBerikutnya;
			}
			cout << endl;
		}
};
class stacklist
{
	private :
		linkedlist* pSenarai;
	public :
		stacklist()
		{
			pSenarai = new linkedlist;
		}
		~stacklist()
		{
			delete pSenarai;
		}
		void push(string n, string p, int np)
		{
			pSenarai->sisipPertama(n,p,np);
		}
		void pop()
		{
			pSenarai->hapusPertama();	
		}
		bool apaKosong()
		{
			return (pSenarai->apaKosong());
		}
		void tampilTumpukan()
		{
			pSenarai->tampilSenarai();
		}
};
int main()
{
	stacklist stack;
	int pilih, no;
	string nama, posisi;
	do 
	{
		cout << "\n-----------------------------------------------------------" << endl;
		cout<< "		QUEUE MENGGUNAKAN LINKED LIST		" <<endl<< endl;
		cout<<"1. Enqueque"<<endl;
		cout<<"2. Dequeque"<<endl;
		cout<<"3. TAMPIL"<<endl;
		cout<<"4. EXIT"<<endl<<endl;
		cout<<"Pilih (1-4) : ";
		cin>>pilih;
		cout<<"Data pemail bola "<<endl;
		cout<<"-----------------"<<endl;
		switch(pilih)
		{
			case 1 :
				cout << "\nNo Punggung : "; cin >> no;
				cin.ignore(256,'\n');
				cout << "Nama : "; getline(cin,nama);
				cout << "Posisi : "; getline(cin,posisi);
				stack.push(nama,posisi,no);
				break;
			case 2 :
				stack.pop();
				break;
			case 3 :
				stack.tampilTumpukan();
				break;
			case 4 :
				exit(0);
				break;
			default :
				cout << "pilihan yang anda masukkan salah!!!"<<endl;
		}
	} while (true);
	getch();
	return 0;
}
