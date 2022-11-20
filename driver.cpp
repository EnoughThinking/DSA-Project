#include <iostream>
#include <unordered_map>
#include "Part1/Btree.h"
#include "Part3/AVL.h"
#include "Part2/BST.h"
#include "utilities/FileHandler.h"
#include "Test/generalTesting.h"
#include "Test/BtreeComparaison.h"
#include <filesystem>
using namespace std;

enum Trees
{
  Bst,
  Avl,
  Btree
};

const Trees Type = Bst;

template <typename TreeType>
TreeType &getTree()
{
  if (Type == Bst)
  {
    static BST TREE;
    TREE.InsertSortedArray(FileHandler().getALLPatient());
    return TREE;
  }
  else if (Type == Avl)
  {
    static AvlTree TREE;
    TREE.InsertSortedArray(FileHandler().getALLPatient());
    return TREE;
  }
  else
  {
    static BTree TREE;
    TREE.InsertSortedArray(FileHandler().getALLPatient());
    return TREE;
  }
}

template <typename TreeType>
void HandleTree(vector<TreeType> &AllTrees)
{
}

void EnterMedicalinfos(MedicalInfo &medicalInfo)
{
  string Allergeies, CD, Note, Time;
  float BP, HR;
  char Depart;
  vector<string> MedicalTaken;

  cout << "Enter a Chronic Disease of the Patient if available\t";
  cin >> CD;
  cout << "Enter the Allergies of the Patient\t";
  cin >> Allergeies;
  cout << "Enter the current Blood Pressure of the Patient: ";
  cin >> BP;
  cout << "Enter the Heart Rate in BPS of the Patient: ";
  cin >> HR;

  cout << "Enter the Medicals taken by the Patient (-1) to quit";
  string medical;
  do
  {
    cin >> medical;
    MedicalTaken.push_back(medical);
  } while (medical != "-1");

  medicalInfo.setAllergies(Allergeies);
  medicalInfo.setCd(CD);
  medicalInfo.setDepartment(Depart);
  medicalInfo.setMedicalstaken(MedicalTaken);
  medicalInfo.setBP(BP);
  medicalInfo.setHr(HR);
  medicalInfo.setNote(Note);
  medicalInfo.setTime(Time);
}

void enterPatient(Patient &patient)
{
  string fullName, bDay, entryDate, adress, tel, ABO;
  char FM;
  MedicalInfo info;

  cout << "Enter the name of the patient : ";
  getline(cin, fullName);
  cout << "Enter the Adress of the patient : ";
  getline(cin, adress);
  cout << "Enter the Birth Date of the patient \" dd/mm/yyyy \" : ";
  cin >> bDay;
  cout << "Enter the gender of the patient ( M for male & F for female) : ";
  cin >> FM;
  cout << "Enter the blood type of the patient : ";
  cin >> ABO;
  cout << "Enter the phone number of the patient : ";
  cin >> tel;
  cout << "Today's date : \" dd/mm/yyyy \": ";
  cin >> entryDate;

  EnterMedicalinfos(info);

  patient.setAbo(ABO);
  patient.setAddress(adress);
  patient.setBday(bDay);
  patient.setFm(FM);
  patient.setMedicalInfo(info);
  patient.setName(fullName);
  patient.setPhone(tel);
}

int main()
{
}