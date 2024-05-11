#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

struct student_t
{
    char id[12];
    char name[40];
    char year[5];
    enum gender_t gender;
    struct dorm_t *dorm;
};

struct student_t create_student(char *_id, char *_name, char *_year,
                                enum gender_t _gender);

struct student_t assign_student(struct student_t *_student, struct dorm_t *_dorm, int _indexStudent, int _indexDorm);

struct student_t empty_dorm(struct dorm_t *_dorm, struct student_t *_student, int _indexStudent, int _indexDorm);

struct student_t move_student(struct student_t *_student, struct dorm_t *_dorm, int _indexStudent, int _indexDorm);

void print_student_detail(struct student_t *_student, int _index);

void print_student(struct student_t *_student, int _index);

#endif
