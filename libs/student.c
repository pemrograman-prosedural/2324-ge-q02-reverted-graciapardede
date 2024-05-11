#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

struct student_t create_student(char *_id, char *_name, char *_year,
                                enum gender_t _gender) {
    struct student_t student;

    strcpy(student.id, _id);
    strcpy(student.name, _name);
    strcpy(student.year, _year);
    student.gender = _gender;
    student.dorm = NULL;
    
    return student;
}

struct student_t assign_student(struct student_t *_student, struct dorm_t *_dorm, int _indexStudent, int _indexDorm) {
    if (_dorm[_indexDorm].residents_num < _dorm[_indexDorm].capacity) {
        _dorm[_indexDorm].residents_num++;
        _student[_indexStudent].dorm = &_dorm[_indexDorm];
    }
    
    return _student[_indexStudent];
}

struct student_t move_student(struct student_t *_student, struct dorm_t *_dorm, int _indexStudent, int _indexDorm) {
    if (_student[_indexStudent].dorm == NULL) {
        _dorm[_indexDorm].residents_num++;
        _student[_indexStudent].dorm = &_dorm[_indexDorm];
    } else {
        _student[_indexStudent].dorm->residents_num--;
        if (_dorm[_indexDorm].residents_num < _dorm[_indexDorm].capacity) {
        _dorm[_indexDorm].residents_num++;
        _student[_indexStudent].dorm = &_dorm[_indexDorm];
        }
    }
    
    return _student[_indexStudent];
}

struct student_t empty_dorm(struct dorm_t *_dorm, struct student_t *_student, int _indexStudent, int _indexDorm) {
    _dorm[_indexDorm].residents_num--;
    _student[_indexStudent].dorm = 0;
    printf("P");
    return _student[_indexStudent];
}

void print_student_detail(struct student_t *_student, int _index) {
    for (int i = 0; i < _index; i++)
    {
        char *_gender;
        if (_student[i].gender == GENDER_MALE) {
            _gender = "male";
        } else {
            _gender = "female";
        }

        if (_student[i].dorm == NULL) {
            printf("%s|%s|%s|%s|unassigned\n", _student[i].id, _student[i].name, _student[i].year, _gender);
        } else {
            printf("%s|%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, _gender, _student[i].dorm->name);
        }
    }
    fflush(stdout);
}


void print_student(struct student_t *_student, int _index) {
    for (int i = 0; i < _index; i++)
    {
        char *_gender;
        if (_student[i].gender == GENDER_MALE) {
            _gender = "male";
        } else {
            _gender = "female";
        }
        printf("%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, _gender);
    }
    
}