import java.util.*;
import java.io.*;
class Student implements Comparable<Student>{
    private String name;
    private int totalMarks;
    Student(String name,int totalMarks){
        this.name = name;
        this.totalMarks = totalMarks;
    }
    public String getName(){
        return name;
    }
    public int getMarks(){
        return totalMarks;
    }

    public int compareTo(Student other){
        return Integer.compare(other.getMarks(), this.getMarks());
    }
}
public class FileSample{
    public static void main(String[] args) throws IOException{
        if(args.length==0){
            System.out.println("** Mention file name in command line **");
            return;
        }
        String filename = args[0];

        Student stu1 = new Student("Alex",75);
        Student stu2 = new Student("Nivi",85);
        Student stu3 = new Student("Aravind",95);
        Student stu4 = new Student("Rahul",65);

        List<Student> students = new ArrayList<>();
        students.add(stu1);
        students.add(stu2);
        students.add(stu3);
        students.add(stu4);

        Collections.sort(students);

        try(PrintWriter writer = new PrintWriter(new FileWriter(filename))){
            writer.println("Rank\t Name\t Marks");
            int rank=1;
            for(Student student: students){
                writer.println(rank + "\t" + student.getName() + "\t" + student.getMarks());
                rank++;
            }

            Student bestStudent = students.get(0);
            System.out.println("** Best student **\nName : "+bestStudent.getName()+"\nMarks : "+bestStudent.getMarks());

            bestStudent = null;
            System.gc();
        }
        catch(Exception exp){
            System.out.println(exp);
        }
        /*
        try (PrintWriter writer = new PrintWriter(new FileWriter(filename))) {
            writer.println("Rank\tName\tMarks");
            int rank = 1;
            for (Student student : students) {
                writer.println(rank + "\t" + student.getName() + "\t" + student.getMarks());
                rank++;
            }

            Student bestStudent = students.get(0);
            System.out.println("Best performing student: " + bestStudent.getName() + " - Marks: " + bestStudent.getMarks());


            bestStudent = null;
            System.gc(); // Requesting garbage collection
        } catch (IOException e) {
            System.out.println("An error occurred while writing to the file: " + e.getMessage());
        }

        Student[] students = {stu1,stu2,stu3,stu4};
        Student max = students[0];
        for(int i=0;i<students.length;i++){
            if(students[i].getMarks()>max.getMarks()){
                max = students[i];
            }
        }
        */

    }
}