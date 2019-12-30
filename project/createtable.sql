create table class
(
    c_id serial primary key,
    class_name varchar(40) not null
);

create table subject
(
    sub_id serial primary key,
    c_id int references class on delete cascade on update cascade,
    sub_name varchar(40)
);
create table Assignment
(
    a_no serial primary key,
    a_name varchar(40),
    sub_id int references subject on delete set null on update cascade
);

create table user_data
(
    email varchar(50) primary key,
    salt varchar(100) ,
    passhash varchar(64) not null
);

create table Teacher
(
    t_id serial primary key,
    first_name varchar(30) not null,
    last_name varchar(30) not null,
    email varchar(50) references user_data on delete cascade on update cascade 
);

create table batch
(
    b_id serial primary key,
    batch_name varchar(40),
    c_id int references class on delete cascade on update cascade,
    t_id int references Teacher on delete cascade on update cascade
);

create table student
(
    roll_no int primary key,
    c_id int references class on delete set null on update cascade,
    b_id int references batch on delete set null on update cascade,
    first_name varchar(30) not null,
    last_name varchar(30) not null,
    email varchar(50) references user_data on delete set null on update cascade,
    year int
);


create table program
(
    p_id serial primary key,
    a_no int references Assignment on delete cascade on update cascade,
    t_id int references Teacher on delete set null on update cascade,
    question text,
    expected_ouput text,
    last_date_of_submission date,
    date_of_creation date
);


create table submission
(
    sub_id serial primary key,
    roll_no int references student on delete cascade on update cascade,
    p_id int references program on delete cascade on update cascade,
    sub_date date,
    program text,
    processed_program text,
    plagiarism_score float,
    comment text,
    marks int CHECK (marks in (1,2,3,4,5))
    
);


