#include <stdio.h>
#include <windows.h>
#include <string.h>

int num,user_i;
char *str;
char user[20],passwd[20];
struct {                                                   
    char users[20][20];
    char passwds[20][20];
}vip;

void _exit()
{
    {
            num=6;
            while(num--)
            {
                system("cls");
                printf("感谢使用本系统%d",num);
                Sleep(1000);
            }
            exit(0);
        }
}

void add()
{
    int i=0;
    printf("用户名>>>");
    scanf("%s",user);
    while(i<=user_i)
    {
        str=strstr(vip.users[i],user);
        if(str!=NULL)
            break;
        i++;
    }
    if(str==NULL)
    {
        printf("密码>>>");
        scanf("%s",passwd);
        user_i++;
        strcpy(vip.users[user_i],user);
        strcpy(vip.passwds[user_i],passwd);
        printf("用户添加成功,现在共有%d个用户\n",user_i+1);
    }
    else
        printf("添加失败，用户已存在\n"); 
}

void close()
{
    int i=0;
    printf("请输入用户名>>>");
    scanf("%s",user);
    while(i<=user_i)
    {
        str=strstr(vip.users[i],user);
        if(str!=NULL)
            break;
        i++;
    }
    if(str!=NULL)
    {
        while(i<user_i)
        {
            strcpy(vip.users[i],vip.users[i+1]);
            strcpy(vip.passwds[i],vip.passwds[i+1]);
            i++;
        }
        user_i--;
        strcpy(vip.users[i],"\0");
        strcpy(vip.passwds[i],"\0");
        printf("用户删除成功,现在共有%d个用户\n",user_i+1);
    }
    else
        printf("删除失败,用户不存在\n");
}

void show(int i)                                         
{
    int show_i;
    printf("序号\t用户名\t密码\n");
    for(show_i=0;show_i<=i;show_i++)
    {
        printf("%d\t%s\t%s\n",show_i+1,vip.users[show_i],vip.passwds[show_i]);
    }
}

void show_indivi(int i)
{
    printf("序号\t用户名\t密码\n");
    printf("%d\t%s\t%s\n",i+1,vip.users[i],vip.passwds[i]);
}
void amend()
{
    int i=0;
    printf("请输入用户名>>>");
    scanf("%s",user);
    while(i<=user_i)
    {
        str=strstr(vip.users[i],user);
        if(str!=NULL)
            break;
        i++;
    }
    if(str!=NULL)
    {
        if(strcmp(vip.users[0],user)!=0)
        {
            strcpy(vip.users[i],user);
            printf("请输入新密码>>>");
            scanf("%s",passwd);
            strcpy(vip.passwds[i],passwd);
             printf("更新成功\n");
        }
        else
            printf("此操作无法修改管理员的信息\n");
    }
    else
        printf("更新失败，用户不存在\n");
}

void amend_admin()
{
    printf("请输入新用户名>>>");
    scanf("%s",user);
    printf("请输入新密码>>>");
    scanf("%s",passwd);
    strcpy(vip.users[0],user);
    strcpy(vip.passwds[0],passwd);
    printf("更新成功\n");
}
int main()
{
    
    int option,i=0;                                                 
    printf("*********第一次登录请设置管理员*********\n");
    printf("请设置管理员账号:");
    scanf("%s",&vip.users[0]);
    printf("请设置管理员密码:");
    scanf("%s",vip.passwds[0]);
    user_i=0;
    printf("设置成功!\n");
    printf("管理员账号为:%s\n",vip.users[0]);
    printf("管理员密码为:%s\n",vip.passwds[0]);
    system("pause");
    up:
    system("cls");
    while(1)
    {
        printf("请输入用户名(输入exit退出):");
        scanf("%s",&user);
        if(!strcmp(user,"exit"))
            _exit();
        printf("请输入密码:");
        scanf("%s",&passwd);
        if(!strcmp(user,vip.users[0]))
            if(!strcmp(passwd,vip.passwds[0]))
            {
                printf("*********登录成功,欢迎管理员*********\n");
                while(1)
                {
                    printf("*********操作目录*********\n"
                        "0.返回界面\n"
                        "1.添加会员信息\n"
                        "2.删除会员信息\n"
                        "3.查看会员信息\n"
                        "4.修改会员信息\n"
                        "5.修改管理员信息\n"
                        "6.退出程序\n"
                        );
                    printf(">>>");
                    scanf("%d",&option);
                    switch(option)
                    {
                        case 0:goto up;break;
                        case 1:printf("*********添加会员操作*********\n");add();break;
                        case 2:printf("*********删除会员操作*********\n");close();break;
                        case 3:printf("*********查看会员操作*********\n");show(user_i);break;
                        case 4:printf("*********修改会员操作*********\n");amend();break;
                        case 5:printf("*********修改管理员操作*********\n");amend_admin();break;
                        case 6:_exit();break;
                    }
                }
            }
        while(i<=user_i)
        {
            str=strstr(vip.users[i],user);
            if(str!=NULL)
                break;
            i++;
        }
        if(str!=NULL)
            if(!strcmp(vip.passwds[i],passwd))
            {
                printf("*********登陆成功，欢迎%s*********\n",user);
                while(1)
                {
                    printf("*********操作目录*********\n"
                        "0.返回界面\n"
                        "1.查看个人信息\n"
                        "2.退出程序\n"
                        );
                    printf(">>>");
                    scanf("%d",&option);
                    switch(option)
                    {
                        case 0:goto up;break;
                        case 1:printf("*********查看个人信息操作*********\n");show_indivi(i);break;
                        case 2:_exit();break;
                    }
                }
            }
    }
    return 0;
}
