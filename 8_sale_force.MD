mail = parthlimsade@gmail.com
pass = parthlimsade@3376

parthlimsade_ivw649gbp0z0@gmail.com
Parth@3376

# Salesforce Practical — Full Beginner Notes

This practical creates:

- A **Lightning App**
- A **Custom Object (Student)**
- Custom Fields
- An **Apex Class**
- Inserts records using Apex code

---

# 1. Login to Salesforce

Open:

[Salesforce Login](https://login.salesforce.com?utm_source=chatgpt.com)

Enter:

- Username
- Password

Then click **Log In**

### Important

If Salesforce asks for OTP verification:

- Check your email
- Enter verification code

---

# 2. Open Setup

After login:

1. Look at top-right corner
2. Click ⚙️ **Gear Icon**
3. Click **Setup**

This opens Salesforce admin settings.

---

# 3. Create New Lightning App

Inside Setup:

1. Search **App Manager** in Quick Find
2. Open **App Manager**
3. Click **New Lightning App**

---

# 4. Fill Lightning App Details

Example values:

| Field          | Value                                 |
| -------------- | ------------------------------------- |
| App Name       | Student Management System             |
| Developer Name | Auto-filled                           |
| Description    | Application to manage student records |

Click:

- **Next**
- Keep clicking **Next**
- Finally click **Save & Finish**

---

# 5. Create Custom Object

Now create database table/object.

### Steps

1. Go to **Object Manager**
2. Click **Create**
3. Select **Custom Object**

---

# 6. Fill Custom Object Details

Use these values:

| Field        | Value        |
| ------------ | ------------ |
| Label        | Student      |
| Plural Label | Students     |
| Object Name  | Student      |
| Record Name  | Student Name |

Then:

✅ Tick:

- Launch New Custom Tab Wizard

Click:

- **Save**

---

# What is happening here?

Salesforce creates:

```text
Student__c
```

This becomes your custom database table.

---

# 7. Create Fields

Now create columns inside Student object.

Go to:

```text
Object Manager → Student → Fields & Relationships
```

Click:

```text
New
```

Create these fields one by one.

---

# Field 1 — Student Name

Usually already created automatically.

Type:

```text
Text
```

---

# Field 2 — Roll Number

| Property  | Value       |
| --------- | ----------- |
| Data Type | Number      |
| Label     | Roll Number |

Field API Name becomes:

```text
Roll_Number__c
```

---

# Field 3 — Email

| Property  | Value |
| --------- | ----- |
| Data Type | Email |
| Label     | Email |

API Name:

```text
Email__c
```

---

# Field 4 — Course

| Property  | Value  |
| --------- | ------ |
| Data Type | Text   |
| Label     | Course |

API Name:

```text
Course__c
```

---

# Field 5 — Marks

| Property  | Value  |
| --------- | ------ |
| Data Type | Number |
| Label     | Marks  |

API Name:

```text
Marks__c
```

---

# VERY IMPORTANT NOTE

Salesforce automatically adds:

```text
__c
```

to custom field names.

Example:

| Label | API Name   |
| ----- | ---------- |
| Marks | Marks\_\_c |
| Email | Email\_\_c |

You MUST use API names in Apex code.

---

# 8. Open Developer Console

Steps:

1. Click profile icon (top-right)
2. Click:

```text
Developer Console
```

New window opens.

---

# 9. Create Apex Class

Inside Developer Console:

1. Click:

```text
File → New → Apex Class
```

2. Name it:

```text
StudentController
```

3. Click OK

---

# 10. Write Apex Code

Paste this code:

```java
public class StudentController {

    public static void createStudent() {

        Student__c s = new Student__c();

        s.Student_Name__c = 'Rohit Sharma';

        s.Roll_Number__c = 101;

        s.Email__c = 'rohit@gmail.com';

        s.Course__c = 'Computer Science';

        s.Marks__c = 85;

        insert s;

        System.debug('Student record inserted successfully');
    }
}
```

---

# Understanding the Code

---

## Create Object Variable

```java
Student__c s = new Student__c();
```

Creates new Student record.

---

## Set Values

```java
s.Student_Name__c = 'Rohit Sharma';
```

Stores student name.

---

```java
s.Roll_Number__c = 101;
```

Stores roll number.

---

```java
s.Email__c = 'rohit@gmail.com';
```

Stores email.

---

```java
s.Course__c = 'Computer Science';
```

Stores course.

---

```java
s.Marks__c = 85;
```

Stores marks.

---

## Insert Record

```java
insert s;
```

Saves record into Salesforce database.

---

## Debug Message

```java
System.debug('Student record inserted successfully');
```

Shows message in logs.

---

# 11. Save the Class

Press:

```text
Ctrl + S
```

or click:

```text
File → Save
```

---

# 12. Execute Apex Code

Now run the method.

Inside Developer Console:

```text
Debug → Open Execute Anonymous Window
```

Paste:

```java
StudentController.createStudent();
```

Tick:

```text
Open Log
```

Click:

```text
Execute
```

---

# 13. Verify Record

Open App Launcher (9 dots icon).

Go to:

```text
Your App → Students
```

You should see inserted record.

---

# Common Errors + Fixes

---

# Error 1 — Object Does Not Exist

```text
Invalid type: Student__c
```

### Fix

You forgot to create custom object.

---

# Error 2 — Field Does Not Exist

```text
No such column
```

### Fix

Field API name is wrong.

Check:

```text
Object Manager → Student → Fields
```

Use exact API names.

---

# Error 3 — Duplicate Object Name

```text
Object name already in use
```

### Fix

Use different object name like:

```text
StudentData
```

---

# Error 4 — Permission Error

### Fix

Use Developer Edition account.

Create free account:

[Salesforce Developer Signup](https://developer.salesforce.com/signup?utm_source=chatgpt.com)

---

# Final Flow Summary

```text
Login
↓
Setup
↓
App Manager
↓
Create Lightning App
↓
Create Custom Object
↓
Create Fields
↓
Open Developer Console
↓
Create Apex Class
↓
Run Execute Anonymous
↓
Record Inserted
```

# Small Extra Tip

You can insert multiple students by repeating:

```java
Student__c s2 = new Student__c();
```

and inserting another record.
