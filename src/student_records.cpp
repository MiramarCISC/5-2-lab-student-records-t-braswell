#include "student_records.hpp"
#include <iostream>

using namespace std;

bool isValidStudentId(string id) {
    // TODO:
    // A valid ID should have at least 3 characters.
    // A valid ID should start with an uppercase letter.
    // Hint: You may compare characters directly, such as id[0] >= 'A'.
  return ((id[0] >= 'A' and id[0]<= 'Z' ) and id.length()>=3);
}

bool isValidScore(double score) {
  return (score >= 0 && score <= 100);
}

void printStudent(const Student& student) {
    cout << student.id << " "
         << student.name << " "
         << student.score << " "
         << determineLetterGrade(student.score)
         << endl;
}

void printStudents(const Student students[], int size) {
    if (students == nullptr || size <= 0) {
        cout << "No students to print." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        printStudent(students[i]);
    }
}

double calculateAverageScore(const Student students[], int size) {
    // TODO:
    // If the array is null or size is invalid, return 0.0.
    // Otherwise, return the average score.
       
  if (students==nullptr or size < 1){
      return 0.0; }
  double sum=0;
  for (int i=0; i < size; ++i) {
    sum=sum+ students[i].score;
  }
  return sum/double(size);
}

double findHighestScore(const Student students[], int size) {
    // TODO:
    // If the array is null or size is invalid, return 0.0.
    // Otherwise, return the highest score.
      if (students == nullptr or size < 1){
	return 0.0; }
        double maxVal=students[0].score;
	for (int i = 0; i < size; ++i) {
	  if (students[i].score >= maxVal) {
	maxVal=students[i].score;
      }
    }
    return maxVal;
}

int findStudentById(const Student students[], int size, string targetId) {
    // TODO:
    // Search by comparing students[i].id to targetId.
    // Return the index of the matching student.
    // Return -1 if no student is found.
      if (students == nullptr or size < 1){
      return -1; }
      for (int i = 0; i < size; ++i) {
    if (students[i].id == targetId) {
      return i;     
    }
  }
      return -1;
}

char determineLetterGrade(double average) {
  if (average >= 90) {
    return 'A';
  }

  if (average >= 80) {
    return 'B';
  }
  if (average >= 70) {
    return 'C';
  }
  if (average >= 60) {
    return 'D';
  }
  else return 'F';
}
