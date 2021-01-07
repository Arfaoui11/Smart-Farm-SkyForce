#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verif.h"
#include "agents.h"
#include "clients.h"
#include "vol.h"
#include "vo.h"
#include "heb.h"
#include "lv.h"
#include "volp.h"
#include "vop.h"
#include "hebp.h"
#include "lvp.h"
#include "reclamation.h"

void on_buttonLogin_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
	FILE*f;
	FILE*ftemp;
	FILE*f1;
	GtkWidget *input1,*input2,*interface1,*interface2,*interface3,*interface4,*interface5,*interface6,*label=NULL;
	GtkWidget *output1,*output2,*output3,*output4,*output5;
	char nom[50],login[50],password[50],email[50],cin[50],num[50],mes[100];
	int verf=0;
	nouveau n,p;
	f=fopen("/home/skander/Desktop/sky-travel/src/personne.txt","r");
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
	interface1=lookup_widget(objet_graphique,"interface1");
	interface2=lookup_widget(objet_graphique,"interface2");
	interface3=lookup_widget(objet_graphique,"interface3");
	interface4=lookup_widget(objet_graphique,"interface4");
	interface5=lookup_widget(objet_graphique,"interface5");
	interface6=lookup_widget(objet_graphique,"interface6");
	input1=lookup_widget(objet_graphique,"entryLogin");
	input2=lookup_widget(objet_graphique,"entryMdp");
	strcpy(login,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
	verf=verif(login,password);
	if(verf==1)
	{
		interface3=create_interface3();
		gtk_widget_show(interface3);
		while(fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id)!=EOF)
		{
			if(strcmp(login,n.login)==0 && strcmp(password,n.password)==0)
			{
				strcpy(nom,n.nom);
				strcpy(login,n.login);
				strcpy(email,n.email);
				strcpy(cin,n.cin);
				strcpy(num,n.num);
				fprintf(ftemp,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
			}
		}
		output1=lookup_widget(interface3,"label18");
		output2=lookup_widget(interface3,"label19");
		output3=lookup_widget(interface3,"label20");
		output4=lookup_widget(interface3,"label21");
		output5=lookup_widget(interface3,"label22");
		gtk_label_set_text(GTK_LABEL(output1),nom);
		gtk_label_set_text(GTK_LABEL(output2),login);
		gtk_label_set_text(GTK_LABEL(output3),email);
		gtk_label_set_text(GTK_LABEL(output4),cin);
		gtk_label_set_text(GTK_LABEL(output5),num);
		gtk_widget_show(interface3);
		gtk_widget_destroy(interface1);
		
	}
	else if(verf==2)
	{
		interface6=create_interface6();
		gtk_widget_show(interface6);
		while(fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id)!=EOF)
		{
			if(strcmp(login,n.login)==0 && strcmp(password,n.password)==0)
			{
				strcpy(nom,n.nom);
				strcpy(login,n.login);
				strcpy(email,n.email);
				strcpy(cin,n.cin);
				strcpy(num,n.num);
				fprintf(ftemp,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
			}
			if(n.id==1)
			{
				f1=fopen("/home/skander/Desktop/sky-travel/src/clients.txt","a+");
				fprintf(f1,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
				fclose(f1);
			}	
		}
		output1=lookup_widget(interface6,"label62");
		output2=lookup_widget(interface6,"label61");
		output3=lookup_widget(interface6,"label57");
		output4=lookup_widget(interface6,"label58");
		output5=lookup_widget(interface6,"label59");
		gtk_label_set_text(GTK_LABEL(output1),nom);
		gtk_label_set_text(GTK_LABEL(output2),login);
		gtk_label_set_text(GTK_LABEL(output3),email);
		gtk_label_set_text(GTK_LABEL(output4),cin);
		gtk_label_set_text(GTK_LABEL(output5),num);
		gtk_widget_destroy(interface1);
		gtk_widget_show(interface6);
	}
	else if(verf==3)
	{
		interface4=create_interface4();
		gtk_widget_show(interface4);
		while(fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id)!=EOF)
		{
			if(strcmp(login,n.login)==0 && strcmp(password,n.password)==0)
			{
				strcpy(nom,n.nom);
				strcpy(login,n.login);
				strcpy(email,n.email);
				strcpy(cin,n.cin);
				strcpy(num,n.num);
				fprintf(ftemp,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
			}
			if(n.id==2)
			{
				f1=fopen("/home/skander/Desktop/sky-travel/src/agents.txt","a+");
				fprintf(f1,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
				fclose(f1);
			}	
		}
		output1=lookup_widget(interface4,"label666");
		output2=lookup_widget(interface4,"label29");
		output3=lookup_widget(interface4,"label30");
		output4=lookup_widget(interface4,"label31");
		output5=lookup_widget(interface4,"label32");
		gtk_label_set_text(GTK_LABEL(output1),nom);
		gtk_label_set_text(GTK_LABEL(output2),login);
		gtk_label_set_text(GTK_LABEL(output3),email);
		gtk_label_set_text(GTK_LABEL(output4),cin);
		gtk_label_set_text(GTK_LABEL(output5),num);
		gtk_widget_show(interface4);
		gtk_widget_destroy(interface1);
	}
	else if(verf==4)
	{
		interface5=create_interface5();
		gtk_widget_show(interface5);
		while(fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id)!=EOF)
		{
			if(strcmp(login,n.login)==0 && strcmp(password,n.password)==0)
			{
				strcpy(nom,n.nom);
				strcpy(login,n.login);
				strcpy(email,n.email);
				strcpy(cin,n.cin);
				strcpy(num,n.num);
				fprintf(ftemp,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
			}
		}
		output1=lookup_widget(interface5,"label47");
		output2=lookup_widget(interface5,"label46");
		output3=lookup_widget(interface5,"label42");
		output4=lookup_widget(interface5,"label43");
		output5=lookup_widget(interface5,"label44");
		gtk_label_set_text(GTK_LABEL(output1),nom);
		gtk_label_set_text(GTK_LABEL(output2),login);
		gtk_label_set_text(GTK_LABEL(output3),email);
		gtk_label_set_text(GTK_LABEL(output4),cin);
		gtk_label_set_text(GTK_LABEL(output5),num);
		gtk_widget_show(interface5);
		gtk_widget_destroy(interface1);
	}	
	else
	{
		label=lookup_widget(objet_graphique,"label63");
		strcpy(mes,"Cet utilisateur n'existe pas");
		gtk_label_set_text(GTK_LABEL(label),mes);
	}
	fclose(f);
	fclose(ftemp);
}

/*void on_buttonCc2_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
	GtkWidget *window1,*window2,*input1,*input2,*input3,*input4,*input5,*input6;
	nouveau n;
	window1=lookup_widget(objet_graphique,"interface1");	
	window2=lookup_widget(objet_graphique,"interface2");
	input1=lookup_widget(window2,"entry1");
	input2=lookup_widget(window2,"entry2");
	input3=lookup_widget(window2,"entry3");
	input4=lookup_widget(window2,"entry4");
	input5=lookup_widget(window2,"entry5");
	input6=lookup_widget(window2,"entry6");
	strcpy(n.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(n.login,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(n.password,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(n.email,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(n.cin,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(n.num,gtk_entry_get_text(GTK_ENTRY(input6)));
	n.id=1;
	ajouter(n);
	gtk_widget_destroy(window2);
	window1=create_interface1();
	gtk_widget_show(window1);
	
}


void on_buttonMc_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window3,*window8;
	window3=lookup_widget(button,"interface3");
	window8=lookup_widget(button,"interface8");
	gtk_widget_destroy(window3);
	window8=create_interface8();
	gtk_widget_show(window8);
}


void on_buttonDes_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
	GtkWidget *window1,*window3,*window7;
	window3=lookup_widget(objet_graphique,"interface3");
	window7=lookup_widget(objet_graphique,"interface7");
	window7=create_interface7();
	gtk_widget_show(window7);
	gtk_widget_hide(window3);
}
void on_buttonDec_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window1,*window3;
	window1=lookup_widget(button,"interface1");
	window3=lookup_widget(button,"interface3");
	gtk_widget_destroy(window3);
	window1=create_interface1();
	gtk_widget_show(window1);
}


void on_buttonMca_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window4,*window9;
	window4=lookup_widget(button,"interface4");
	window9=lookup_widget(button,"interface9");
	gtk_widget_destroy(window4);
	window9=create_interface9();
	gtk_widget_show(window9);	
}


void on_buttonDeca_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window1,*window4;
	window1=lookup_widget(button,"interface1");
	window4=lookup_widget(button,"interface4");
	gtk_widget_destroy(window4);
	window1=create_interface1();
	gtk_widget_show(window1);
	remove("/home/skander/Desktop/sky-travel/src/agents.txt");
}


void on_buttonMcp_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window31,*window5;
	window31=lookup_widget(button,"interface31");
	window5=lookup_widget(button,"interface5");
	gtk_widget_destroy(window5);
	window31=create_interface31();
	gtk_widget_show(window31);
}


void on_buttonDecp_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window1,*window5;
	window1=lookup_widget(button,"interface1");
	window5=lookup_widget(button,"interface5");
	gtk_widget_destroy(window5);
	window1=create_interface1();
	gtk_widget_show(window1);
}


void on_buttonMcag_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window33;
	window6=lookup_widget(button,"interface6");
	window33=lookup_widget(button,"interface33");
	gtk_widget_destroy(window6);
	window33=create_interface33();
	gtk_widget_show(window33);
}


void on_buttonDecag_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window1,*window6;
	window1=lookup_widget(button,"interface1");
	window6=lookup_widget(button,"interface6");
	gtk_widget_destroy(window6);
	window1=create_interface1();
	gtk_widget_show(window1);
	remove("/home/skander/Desktop/sky-travel/src/clients.txt");
}


void on_buttonagac_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window27;
	window6=lookup_widget(button,"interface6");
	window27=lookup_widget(button,"interface27");
	gtk_widget_destroy(window6);
	window27=create_interface27();
	gtk_widget_show(window27);
}


void on_buttonagmc_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window27;
	window6=lookup_widget(button,"interface6");
	window27=lookup_widget(button,"interface28");
	gtk_widget_destroy(window6);
	window27=create_interface28();
	gtk_widget_show(window27);
}


void on_buttonagsc_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window27;
	window6=lookup_widget(button,"interface6");
	window27=lookup_widget(button,"interface30");
	gtk_widget_destroy(window6);
	window27=create_interface30();
	gtk_widget_show(window27);
}


void on_buttonnc_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
	GtkWidget *window1,*window2;
	window1=lookup_widget(objet_graphique,"interface1");
	window2=lookup_widget(objet_graphique,"interface2");
	window2=create_interface2();
	gtk_widget_show(window2);
	gtk_widget_destroy(window1);
}


void on_buttoncdes_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
	GtkWidget *window7,*window1,*window3,*output1,*input1,*input2,*input3,*input4,*input5,*input6,*input7;
	FILE*f;
	FILE*ftemp;
	int verf=0;
	char log[50],pass[50],mes[50];
	nouveau n;
	input6=lookup_widget(objet_graphique,"entry7");
	input7=lookup_widget(objet_graphique,"entry8");
	window1=lookup_widget(objet_graphique,"interface1");
	window7=lookup_widget(objet_graphique,"interface7");
	window3=lookup_widget(objet_graphique,"interface3");
	strcpy(log,gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(pass,gtk_entry_get_text(GTK_ENTRY(input7)));
	output1=lookup_widget(window7,"label669");
	verf=verif(log,pass);
	if(verf==1)	
	{	
		supprimer(log,pass);
		window1=create_interface1();
		gtk_widget_destroy(window7);
		gtk_widget_show(window1);
	}	
	else
	{
		strcpy(mes,"Cet utilisateur n'existe pas");
		gtk_label_set_text(GTK_LABEL(output1),mes);		
	}
}


void on_buttonrdes_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
	GtkWidget *window7,*window3,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(f,"%s %s %s %s %s %s",n.nom,n.login,n.password,n.email,n.cin,n.num);
	window3=lookup_widget(objet_graphique,"interface3");
	window3=create_interface3();
	output1=lookup_widget(window3,"label18");
	output2=lookup_widget(window3,"label19");
	output3=lookup_widget(window3,"label20");
	output4=lookup_widget(window3,"label21");
	output5=lookup_widget(window3,"label22");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);		
	gtk_widget_show(window3);
	window7=lookup_widget(objet_graphique,"interface7");
	gtk_widget_destroy(window7);
	fclose(f);
}


void on_buttoncch_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window8,*window3,*combobox1,*input1,*output1,*output2,*output3,*output4,*output5;	
	char mes[50];
	nouveau n;
	FILE*f;
	window3=lookup_widget(button,"interface3");
	window8=lookup_widget(button,"interface8");
	combobox1=lookup_widget(window8,"combobox1");
	input1=lookup_widget(window8,"entry9");
	strcpy(mes,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
	if(strcmp(mes,"nom")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		strcpy(n.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
		supprimer(n.login,n.password);
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"login")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		strcpy(n.login,gtk_entry_get_text(GTK_ENTRY(input1)));
		supprimer(n.login,n.password);
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"password")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		strcpy(n.password,gtk_entry_get_text(GTK_ENTRY(input1)));
		supprimer(n.login,n.password);
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"email")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		strcpy(n.email,gtk_entry_get_text(GTK_ENTRY(input1)));
		supprimer(n.login,n.password);
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"cin")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		strcpy(n.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
		supprimer(n.login,n.password);
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		strcpy(n.num,gtk_entry_get_text(GTK_ENTRY(input1)));
		supprimer(n.login,n.password);
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	gtk_widget_destroy(window8);
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(f,"%s %s %s %s %s %s",n.nom,n.login,n.password,n.email,n.cin,n.num);
	window3=lookup_widget(button,"interface3");
	window3=create_interface3();
	output1=lookup_widget(window3,"label18");
	output2=lookup_widget(window3,"label19");
	output3=lookup_widget(window3,"label20");
	output4=lookup_widget(window3,"label21");
	output5=lookup_widget(window3,"label22");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);		
	gtk_widget_show(window3);	
}
void on_buttonrch_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window8,*window3,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(f,"%s %s %s %s %s %s",n.nom,n.login,n.password,n.email,n.cin,n.num);
	window3=lookup_widget(button,"interface3");
	window3=create_interface3();
	output1=lookup_widget(window3,"label18");
	output2=lookup_widget(window3,"label19");
	output3=lookup_widget(window3,"label20");
	output4=lookup_widget(window3,"label21");
	output5=lookup_widget(window3,"label22");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);		
	gtk_widget_show(window3);
	window8=lookup_widget(button,"interface8");
	gtk_widget_destroy(window8);
	fclose(f);
}


void on_button2_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window9,*window4,*combobox2,*input1,*output1,*output2,*output3,*output4,*output5;	
	char mes[50];
	nouveau n;
	FILE*f;
	window4=lookup_widget(button,"interface4");
	window9=lookup_widget(button,"interface9");
	combobox2=lookup_widget(window9,"combobox2");
	input1=lookup_widget(window9,"entry10");
	strcpy(mes,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
	if(strcmp(mes,"nom")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"login")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.login,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"password")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.password,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"email")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.email,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"cin")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.num,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	gtk_widget_destroy(window9);
	window4=lookup_widget(button,"interface4");
	window4=create_interface4();
	output1=lookup_widget(window4,"label666");
	output2=lookup_widget(window4,"label29");
	output3=lookup_widget(window4,"label30");
	output4=lookup_widget(window4,"label31");
	output5=lookup_widget(window4,"label32");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);		
	gtk_widget_show(window4);
}


void on_button1_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window9,*window4,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(f,"%s %s %s %s %s %s",n.nom,n.login,n.password,n.email,n.cin,n.num);
	window4=lookup_widget(button,"interface4");
	window4=create_interface4();
	output1=lookup_widget(window4,"label666");
	output2=lookup_widget(window4,"label29");
	output3=lookup_widget(window4,"label30");
	output4=lookup_widget(window4,"label31");
	output5=lookup_widget(window4,"label32");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);		
	gtk_widget_show(window4);
	window9=lookup_widget(button,"interface9");
	gtk_widget_destroy(window9);
	fclose(f);
}


void on_buttonaag_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window4,*treeview3;
	window4=lookup_widget(button,"interface4");
	treeview3=lookup_widget(button,"treeview3");
	afficher_agents(treeview3);
}


void
on_buttonaffcat_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*treeview,*combobox;
	window1=lookup_widget(button,"interface6");
	treeview=lookup_widget(window1,"treeview5");
	combobox=lookup_widget(window1,"combobox3");
	if(strcmp("Voyage Organisé",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		afficher_vo(treeview);
	}
	else if(strcmp("Vol",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		afficher_vol(treeview);
	}
	else if(strcmp("Hébergement",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		afficher_heb(treeview);
	}
	else if(strcmp("Location Voiture",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		afficher_lv(treeview);
	}
}


void on_buttonajcat_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*combobox,*window14,*window17,*window20,*window23;
	window6=lookup_widget(button,"interface6");
	window14=lookup_widget(button,"interface14");
	window17=lookup_widget(button,"interface17");
	window20=lookup_widget(button,"interface20");
	window23=lookup_widget(button,"interface23");
	combobox=lookup_widget(window6,"combobox3");
	if(strcmp("Location Voiture",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		gtk_widget_destroy(window6);
		window14=create_interface14();
		gtk_widget_show(window14);
	}
	else if(strcmp("Vol",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		gtk_widget_destroy(window6);
		window17=create_interface17();
		gtk_widget_show(window17);
	}
	else if(strcmp("Hébergement",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		gtk_widget_destroy(window6);
		window20=create_interface20();
		gtk_widget_show(window20);
	}
	else if(strcmp("Voyage Organisé",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		gtk_widget_destroy(window6);
		window23=create_interface23();
		gtk_widget_show(window23);
	}
}


void on_buttonmcat_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window19,*window22,*window6,*combobox,*window16,*window25;
	window6=lookup_widget(button,"interface6");
	window16=lookup_widget(button,"interface16");
	window19=lookup_widget(button,"interface19");
	window22=lookup_widget(button,"interface22");
	window25=lookup_widget(button,"interface25");
	combobox=lookup_widget(window6,"combobox3");
	if(strcmp("Location Voiture",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		gtk_widget_destroy(window6);
		window16=create_interface16();
		gtk_widget_show(window16);
	}
	else if(strcmp("Vol",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		gtk_widget_destroy(window6);
		window19=create_interface19();
		gtk_widget_show(window19);
	}
	else if(strcmp("Hébergement",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		gtk_widget_destroy(window6);
		window22=create_interface22();
		gtk_widget_show(window22);
	}
	else if(strcmp("Voyage Organisé",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		gtk_widget_destroy(window6);
		window25=create_interface25();
		gtk_widget_show(window25);
	}
}


void on_buttonscat_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window18,*window15,*window21,*window24,*combobox;
	window6=lookup_widget(button,"interface6");
	window15=lookup_widget(button,"interface15");
	window18=lookup_widget(button,"interface18");
	window21=lookup_widget(button,"interface21");
	window24=lookup_widget(button,"interface24");
	combobox=lookup_widget(window6,"combobox3");
	if(strcmp("Location Voiture",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		gtk_widget_destroy(window6);
		window15=create_interface15();
		gtk_widget_show(window15);
	}
	else if(strcmp("Vol",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		gtk_widget_destroy(window6);
		window18=create_interface18();
		gtk_widget_show(window18);
	}
	else if(strcmp("Hébergement",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		gtk_widget_destroy(window6);
		window21=create_interface21();
		gtk_widget_show(window21);
	}	
	else if(strcmp("Voyage Organisé",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		gtk_widget_destroy(window6);
		window24=create_interface24();
		gtk_widget_show(window24);
	}
}


void on_buttonrechcat_clicked(GtkWidget *button,gpointer user_data)
{

}


void on_buttonaa_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window4,*window10;
	window4=lookup_widget(button,"interface4");
	window10=lookup_widget(button,"interface10");
	gtk_widget_destroy(window4);
	window10=create_interface10();
	gtk_widget_show(window10);
}


void on_buttonsa_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window4,*window11;
	window4=lookup_widget(button,"interface4");
	window11=lookup_widget(button,"interface11");
	gtk_widget_destroy(window4);
	window11=create_interface11();
	gtk_widget_show(window11);
}


void on_buttoncaag_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window4,*window10,*input1,*input2,*input3,*input4,*input5,*input6,*output1,*output2,*output3,*output4,*output5;
	nouveau n;
	FILE*f;
	window4=lookup_widget(button,"interface4");	
	window10=lookup_widget(button,"interface10");
	input1=lookup_widget(window10,"entry12");
	input2=lookup_widget(window10,"entry13");
	input3=lookup_widget(window10,"entry14");
	input4=lookup_widget(window10,"entry15");
	input5=lookup_widget(window10,"entry16");
	input6=lookup_widget(window10,"entry17");
	strcpy(n.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(n.login,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(n.password,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(n.email,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(n.cin,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(n.num,gtk_entry_get_text(GTK_ENTRY(input6)));
	n.id=2;
	ajouter(n);
	ajouter_agent(n);
	gtk_widget_destroy(window10);
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	window4=create_interface4();
	fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window4,"label666");
	output2=lookup_widget(window4,"label29");
	output3=lookup_widget(window4,"label30");
	output4=lookup_widget(window4,"label31");
	output5=lookup_widget(window4,"label32");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window4);
	fclose(f);
}


void on_Buttonraag_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window10,*window4,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	window10=lookup_widget(button,"interface10");
	window4=lookup_widget(button,"interface4");
	gtk_widget_destroy(window10);	
	window4=create_interface4();
	fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window4,"label666");
	output2=lookup_widget(window4,"label29");
	output3=lookup_widget(window4,"label30");
	output4=lookup_widget(window4,"label31");
	output5=lookup_widget(window4,"label32");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window4);
	fclose(f);
}


void on_buttoncsag_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window4,*window11,*output1,*output2,*output3,*output4,*output5,*input6,*input7;
	FILE*f;
	int verf=0;
	char log[50],pass[50],mes[50];
	nouveau n;
	input6=lookup_widget(button,"entry18");
	input7=lookup_widget(button,"entry19");
	window11=lookup_widget(button,"interface11");
	window4=lookup_widget(button,"interface4");
	strcpy(log,gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(pass,gtk_entry_get_text(GTK_ENTRY(input7)));
	output1=lookup_widget(window11,"label691");
	verf=verif(log,pass);
	if(verf==2)	
	{	
		supprimer(log,pass);
		supprimer_agent(log,pass);
		window11=create_interface11();
		gtk_widget_destroy(window4);
		gtk_widget_show(window11);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		window11=lookup_widget(button,"interface11");	
		window4=lookup_widget(button,"interface4");
		gtk_widget_destroy(window11);	
		window4=create_interface4();
		fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		output1=lookup_widget(window4,"label666");
		output2=lookup_widget(window4,"label29");
		output3=lookup_widget(window4,"label30");
		output4=lookup_widget(window4,"label31");
		output5=lookup_widget(window4,"label32");
		gtk_label_set_text(GTK_LABEL(output1),n.nom);
		gtk_label_set_text(GTK_LABEL(output2),n.login);
		gtk_label_set_text(GTK_LABEL(output3),n.email);
		gtk_label_set_text(GTK_LABEL(output4),n.cin);
		gtk_label_set_text(GTK_LABEL(output5),n.num);
		gtk_widget_show(window4);
		fclose(f);
	}	
	else
	{
		strcpy(mes,"Cet utilisateur n'existe pas");
		gtk_label_set_text(GTK_LABEL(output1),mes);		
	}
}



void on_buttonrsag_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window11,*window4,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	window11=lookup_widget(button,"interface11");
	window4=lookup_widget(button,"interface4");
	gtk_widget_destroy(window11);	
	window4=create_interface4();
	fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window4,"label666");
	output2=lookup_widget(window4,"label29");
	output3=lookup_widget(window4,"label30");
	output4=lookup_widget(window4,"label31");
	output5=lookup_widget(window4,"label32");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window4);
	fclose(f);
}


void on_buttoncmag_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window12,*window13,*output1,*input1,*input2,*input3,*input4,*input5,*input6,*input7;
	FILE*f;
	FILE*ftemp;
	int verf=0;
	char log[50],pass[50],mes[50];
	nouveau n;
	input6=lookup_widget(button,"entry20");
	input7=lookup_widget(button,"entry21");
	window12=lookup_widget(button,"interface12");
	window13=lookup_widget(button,"interface13");
	strcpy(log,gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(pass,gtk_entry_get_text(GTK_ENTRY(input7)));
	output1=lookup_widget(window12,"label697");
	verf=verif(log,pass);
	if(verf==2)	
	{	
		f=fopen("/home/skander/Desktop/sky-travel/src/agents.txt","r");
		ftemp=fopen("/home/skander/Desktop/sky-travel/src/am.txt","w");
		while(fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id)!=EOF)
		{
			if(strcmp(log,n.login)==0 && strcmp(pass,n.password)==0)
			{
				fprintf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
			}
		}
		fclose(f);
		fclose(ftemp);
		window13=create_interface13();
		gtk_widget_destroy(window12);
		gtk_widget_show(window13);
	}	
	else
	{
		strcpy(mes,"Cet agent n'existe pas");
		gtk_label_set_text(GTK_LABEL(output1),mes);		
	}
}


void on_buttonrchag_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window13,*window4,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	window13=lookup_widget(button,"interface13");
	window4=lookup_widget(button,"interface4");
	gtk_widget_destroy(window13);	
	window4=create_interface4();
	fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window4,"label666");
	output2=lookup_widget(window4,"label29");
	output3=lookup_widget(window4,"label30");
	output4=lookup_widget(window4,"label31");
	output5=lookup_widget(window4,"label32");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window4);
	fclose(f);

}


void on_buttoncchag_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window13,*window4,*combobox2,*input1,*output1,*output2,*output3,*output4,*output5;	
	char mes[50];
	nouveau n;
	FILE*f;
	window4=lookup_widget(button,"interface4");
	window13=lookup_widget(button,"interface13");
	combobox2=lookup_widget(window13,"combobox4");
	input1=lookup_widget(window13,"entry22");
	strcpy(mes,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
	if(strcmp(mes,"nom")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/am.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		supprimer_agent(n.login,n.password);
		strcpy(n.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		ajouter_agent(n);
		remove("/home/skander/Desktop/sky-travel/src/am.txt");
	}
	else if(strcmp(mes,"login")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/am.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		supprimer_agent(n.login,n.password);
		strcpy(n.login,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		ajouter_agent(n);
		remove("/home/skander/Desktop/sky-travel/src/am.txt");
	}
	else if(strcmp(mes,"password")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/am.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		supprimer_agent(n.login,n.password);
		strcpy(n.password,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		ajouter_agent(n);
		remove("/home/skander/Desktop/sky-travel/src/am.txt");
	}
	else if(strcmp(mes,"email")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/am.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		supprimer_agent(n.login,n.password);
		strcpy(n.email,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		ajouter_agent(n);
		remove("/home/skander/Desktop/sky-travel/src/am.txt");
	}
	else if(strcmp(mes,"cin")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/am.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		supprimer_agent(n.login,n.password);
		strcpy(n.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		ajouter_agent(n);
		remove("/home/skander/Desktop/sky-travel/src/am.txt");
	}
	else
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/am.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		supprimer_agent(n.login,n.password);
		strcpy(n.num,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		ajouter_agent(n);
		remove("/home/skander/Desktop/sky-travel/src/am.txt");
	}
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(f,"%s %s %s %s %s %s",n.nom,n.login,n.password,n.email,n.cin,n.num);
	gtk_widget_destroy(window13);
	window4=lookup_widget(button,"interface4");
	window4=create_interface4();
	output1=lookup_widget(window4,"label666");
	output2=lookup_widget(window4,"label29");
	output3=lookup_widget(window4,"label30");
	output4=lookup_widget(window4,"label31");
	output5=lookup_widget(window4,"label32");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);		
	gtk_widget_show(window4);
}



void on_buttonrmag_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window12,*window4,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	window12=lookup_widget(button,"interface12");
	window4=lookup_widget(button,"interface4");
	gtk_widget_destroy(window12);	
	window4=create_interface4();
	fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window4,"label666");
	output2=lookup_widget(window4,"label29");
	output3=lookup_widget(window4,"label30");
	output4=lookup_widget(window4,"label31");
	output5=lookup_widget(window4,"label32");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window4);
	fclose(f);
}


void on_buttonmaga_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window4,*window12;
	window4=lookup_widget(button,"interface4");
	window12=lookup_widget(button,"interface12");
	gtk_widget_destroy(window4);
	window12=create_interface12();
	gtk_widget_show(window12);
}


void on_buttoncalv_clicked(GtkWidget *button,gpointer user_data)
{
	lv lv;
	FILE*f;
	FILE*ftemp;
	nouveau n;
	GtkWidget *window14,*window6,*input1,*input2,*input3,*input4,*input5,*output1,*output2,*output3,*output4,*output5;
	window6=lookup_widget(button,"interface6");
	window14=lookup_widget(button,"interface14");
	input1=lookup_widget(window14,"entry23");
	input2=lookup_widget(window14,"entry24");
	input3=lookup_widget(window14,"entry25");
	input4=lookup_widget(window14,"entry26");
	input5=lookup_widget(window14,"entry27");
	strcpy(lv.type,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(lv.nch,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(lv.date_a,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(lv.date_r,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(lv.prix,gtk_entry_get_text(GTK_ENTRY(input5)));
	f=fopen("/home/skander/Desktop/sky-travel/src/lv.txt","a+");
   	fprintf(f,"%s %s %s %s %s\n",lv.type,lv.nch,lv.date_a,lv.date_r,lv.prix);
	fclose(f);
	gtk_widget_destroy(window14);
	window6=create_interface6();
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(ftemp);
	
}



void on_buttonralv_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window14,*output1,*output2,*output3,*output4,*output5;
	FILE*ftemp;
	nouveau n;
	window6=lookup_widget(button,"interface6");
	window14=lookup_widget(button,"interface14");
	gtk_widget_destroy(window14);
	window6=create_interface6();
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(ftemp);
}


void on_buttoncmlv_clicked(GtkWidget *button,gpointer user_data)
{

}


void on_buttoncchlv_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window16,*window6,*combobox4,*input1,*input2,*input3,*output1,*output2,*output3,*output4,*output5,*output6;	
	char mes[50],erreur[50];
	nouveau n;
	char type[50],nch[50];
	FILE*f;
	FILE*ftemp;
	FILE*F;
	lv lv;
	strcpy(erreur,"");
	window6=lookup_widget(button,"interface6");
	window16=lookup_widget(button,"interface16");
	combobox4=lookup_widget(window16,"combobox5");
	input1=lookup_widget(window16,"entry30");
	input2=lookup_widget(window16,"entry31");
	input3=lookup_widget(window16,"entry32");
	output6=lookup_widget(window16,"label713");
	strcpy(type,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(nch,gtk_entry_get_text(GTK_ENTRY(input2)));
	f=fopen("/home/skander/Desktop/sky-travel/src/lv.txt","r");
	while(fscanf(f,"%s %s %s %s %s\n",lv.type,lv.nch,lv.date_a,lv.date_r,lv.prix)!=EOF)
	{
			if(strcmp(type,lv.type)==0 && strcmp(nch,lv.nch)==0)

			{	gtk_label_set_text(GTK_LABEL(output6),erreur);
				strcpy(mes,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4)));
				if(strcmp(mes,"Type")==0)
				{
					supprimerlv(type,nch);
					strcpy(lv.type,gtk_entry_get_text(GTK_ENTRY(input1)));
					F=fopen("/home/skander/Desktop/sky-travel/src/lv.txt","a+");					
					fprintf(F,"%s %s %s %s %s\n",lv.type,lv.nch,lv.date_a,lv.date_r,lv.prix);
					fclose(F);				
				}
				else if(strcmp(mes,"Nb de CH")==0)
				{	
					supprimerlv(type,nch);
					strcpy(lv.nch,gtk_entry_get_text(GTK_ENTRY(input1)));
					F=fopen("/home/skander/Desktop/sky-travel/src/lv.txt","a+");					
					fprintf(F,"%s %s %s %s %s\n",lv.type,lv.nch,lv.date_a,lv.date_r,lv.prix);
					fclose(F);	
				}
				else if(strcmp(mes,"Date début contrat")==0)
				{	
					supprimerlv(type,nch);
					strcpy(lv.date_a,gtk_entry_get_text(GTK_ENTRY(input1)));
					F=fopen("/home/skander/Desktop/sky-travel/src/lv.txt","a+");					
					fprintf(F,"%s %s %s %s %s\n",lv.type,lv.nch,lv.date_a,lv.date_r,lv.prix);
					fclose(F);	
				}
				else if(strcmp(mes,"Date fin contrat")==0)
				{	
					supprimerlv(type,nch);
					strcpy(lv.date_r,gtk_entry_get_text(GTK_ENTRY(input1)));
					F=fopen("/home/skander/Desktop/sky-travel/src/lv.txt","a+");					
					fprintf(F,"%s %s %s %s %s\n",lv.type,lv.nch,lv.date_a,lv.date_r,lv.prix);
					fclose(F);	
				}
				else 
				{	
					supprimerlv(type,nch);
					strcpy(lv.prix,gtk_entry_get_text(GTK_ENTRY(input1)));
					F=fopen("/home/skander/Desktop/sky-travel/src/lv.txt","a+");					
					fprintf(F,"%s %s %s %s %s\n",lv.type,lv.nch,lv.date_a,lv.date_r,lv.prix);
					fclose(F);	
				}
	
			gtk_widget_destroy(window16);
			window6=create_interface6();
			gtk_widget_show(window6);
			ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
			fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
			output1=lookup_widget(window6,"label62");
			output2=lookup_widget(window6,"label61");
			output3=lookup_widget(window6,"label57");
			output4=lookup_widget(window6,"label58");
			output5=lookup_widget(window6,"label59");
			gtk_label_set_text(GTK_LABEL(output1),n.nom);
			gtk_label_set_text(GTK_LABEL(output2),n.login);
			gtk_label_set_text(GTK_LABEL(output3),n.email);
			gtk_label_set_text(GTK_LABEL(output4),n.cin);
			gtk_label_set_text(GTK_LABEL(output5),n.num);
			gtk_widget_show(window6);
			fclose(ftemp);

			}
			else
			{
				strcpy(erreur,"Ce lv n'existe pas");
				gtk_label_set_text(GTK_LABEL(output6),erreur);
			}

			
		
     
	}
	fclose(f);
}


void on_buttonrmlv_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window16,*output1,*output2,*output3,*output4,*output5;
	FILE*ftemp;
	nouveau n;
	window6=lookup_widget(button,"interface6");
	window16=lookup_widget(button,"interface16");
	gtk_widget_destroy(window16);
	window6=create_interface6();
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(ftemp);
}


void on_buttoncslv_clicked(GtkWidget *button,gpointer user_data)
{
	lv lv;
	nouveau n;
	FILE*ftemp;
   	GtkWidget *window12,*window6,*input1,*input2,*output1,*output2,*output3,*output4,*output5;
	window6=lookup_widget(button,"interface6");
	window12=lookup_widget(button,"interface15");
	input1=lookup_widget(window12,"entry28");
	input2=lookup_widget(window12,"entry29");
	strcpy(lv.type,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(lv.nch,gtk_entry_get_text(GTK_ENTRY(input2)));
	supprimerlv(lv.type,lv.nch);
	gtk_widget_destroy(window12);
	window6=create_interface6();
	gtk_widget_show(window6);
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(ftemp);

}


void on_buttonrslv_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window12,*output1,*output2,*output3,*output4,*output5;
	FILE*ftemp;
	nouveau n;
	window6=lookup_widget(button,"interface6");
	window12=lookup_widget(button,"interface15");
	gtk_widget_destroy(window12);
	window6=create_interface6();
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(ftemp);
}


void
on_buttonrajcat_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window17,*output1,*output2,*output3,*output4,*output5;
	FILE*ftemp;
	nouveau n;
	window6=lookup_widget(button,"interface6");
	window17=lookup_widget(button,"interface17");
	gtk_widget_destroy(window17);
	window6=create_interface6();
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(ftemp);
}


void
on_buttoncajcat_clicked (GtkWidget *button,gpointer user_data)
{
	vol v;
	FILE*f;

	FILE*ftemp;
	nouveau n;   
	GtkWidget *window17,*window6,*input1,*input2,*input3,*input4,*input5,*input6,*output1,*output2,*output3,*output4,*output5;
	window6=lookup_widget(button,"interface6");
	window17=lookup_widget(button,"interface17");
	input1=lookup_widget(window17,"entryvcomp");
	input2=lookup_widget(window17,"entryvdest");
	input3=lookup_widget(window17,"entryvdate");
	input4=lookup_widget(window17,"entryvdep");
	input5=lookup_widget(window17,"entryvpx");
	input6=lookup_widget(window17,"entryvpro");
	strcpy(v.comp,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(v.dest,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(v.date,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(v.dep,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(v.prix,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(v.pro,gtk_entry_get_text(GTK_ENTRY(input6)));
	f=fopen("/home/skander/Desktop/sky-travel/src/vol.txt","a+");
   	fprintf(f,"%s %s %s %s %s %s\n",v.dep,v.dest,v.comp,v.date,v.prix,v.pro);
	fclose(f);
	gtk_widget_destroy( window17);
	window6=create_interface6();
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(ftemp);
	
}


void
on_buttoncsvcat_clicked (GtkWidget *button,gpointer user_data)
{
	vol v;
	char erreur[50],comp[50],dest[50];
	nouveau n;
	FILE*ftemp;
	FILE*f;
	strcpy(erreur,"");
   	GtkWidget *window18,*window6,*input1,*input2,*output1,*output2,*output3,*output4,*output5,*output6;
	window6=lookup_widget(button,"interface6");
	window18=lookup_widget(button,"interface18");
	output6=lookup_widget(window18,"label723");
	input1=lookup_widget(window18,"entry34");
	input2=lookup_widget(window18,"entry33");
	strcpy(comp,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(dest,gtk_entry_get_text(GTK_ENTRY(input1)));
	f=fopen("/home/skander/Desktop/sky-travel/src/vol.txt","r");
	while(fscanf(f,"%s %s %s %s %s %s\n",v.dep,v.dest,v.comp,v.date,v.prix,v.pro)!=EOF)
	{
			if(strcmp(dest,v.dest)==0 && strcmp(comp,v.comp)==0)
				{	gtk_label_set_text(GTK_LABEL(output6),erreur);
					supprimervol(v.dest,v.comp);
					gtk_widget_destroy(window18);
					window6=create_interface6();
					gtk_widget_show(window6);
					ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
					fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
					output1=lookup_widget(window6,"label62");
					output2=lookup_widget(window6,"label61");
					output3=lookup_widget(window6,"label57");
					output4=lookup_widget(window6,"label58");
					output5=lookup_widget(window6,"label59");
					gtk_label_set_text(GTK_LABEL(output1),n.nom);
					gtk_label_set_text(GTK_LABEL(output2),n.login);
					gtk_label_set_text(GTK_LABEL(output3),n.email);
					gtk_label_set_text(GTK_LABEL(output4),n.cin);
					gtk_label_set_text(GTK_LABEL(output5),n.num);
					gtk_widget_show(window6);
					fclose(ftemp);

				}
			else
			{
				strcpy(erreur,"Ce vol n'existe pas");
				gtk_label_set_text(GTK_LABEL(output6),erreur);
			}
	}
	fclose(f);
}


void
on_buttonrsvcat_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window18,*output1,*output2,*output3,*output4,*output5;
	FILE*ftemp;
	nouveau n;
	window6=lookup_widget(button,"interface6");
	window18=lookup_widget(button,"interface18");
	gtk_widget_destroy(window18);
	window6=create_interface6();
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(ftemp);
}


void
on_buttonrmvcat_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window19,*output1,*output2,*output3,*output4,*output5;
	FILE*ftemp;
	nouveau n;
	window6=lookup_widget(button,"interface6");
	window19=lookup_widget(button,"interface19");
	gtk_widget_destroy(window19);
	window6=create_interface6();
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(ftemp);
}


void
on_buttoncmvcat_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window19,*window6,*combobox4,*input1,*input2,*input3,*output1,*output2,*output3,*output4,*output5,*output6;	
	char mes[50],erreur[50];
	nouveau n;
	char dest[50],comp[50];
	FILE*f;
	FILE*ftemp;
	FILE*F;
	vol v;
	window6=lookup_widget(button,"interface6");
	window19=lookup_widget(button,"interface19");
	combobox4=lookup_widget(window19,"combobox206");
	input1=lookup_widget(window19,"entry37");
	input2=lookup_widget(window19,"entry35");
	input3=lookup_widget(window19,"entry36");
	output6=lookup_widget(window19,"label726");
	strcpy(dest,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(comp,gtk_entry_get_text(GTK_ENTRY(input3)));
	f=fopen("/home/skander/Desktop/sky-travel/src/vol.txt","r");
	while(fscanf(f,"%s %s %s %s %s %s\n",v.dep,v.dest,v.comp,v.date,v.prix,v.pro)!=EOF)
	{
			if(strcmp(dest,v.dest)==0 && strcmp(comp,v.comp)==0)

			{
				strcpy(mes,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4)));
				if(strcmp(mes,"Destination")==0)
				{
					supprimervol(dest,comp);
					strcpy(v.dest,gtk_entry_get_text(GTK_ENTRY(input1)));
					F=fopen("/home/skander/Desktop/sky-travel/src/vol.txt","a+");					
					fprintf(F,"%s %s %s %s %s %s\n",v.dep,v.dest,v.comp,v.date,v.prix,v.pro);
					fclose(F);				
				}
				else if(strcmp(mes,"Compagnie")==0)
				{	
					supprimervol(dest,comp);
					strcpy(v.comp,gtk_entry_get_text(GTK_ENTRY(input1)));
					F=fopen("/home/skander/Desktop/sky-travel/src/vol.txt","a+");					
					fprintf(F,"%s %s %s %s %s %s\n",v.dep,v.dest,v.comp,v.date,v.prix,v.pro);
					fclose(F);	
				}
				else if(strcmp(mes,"Date")==0)
				{	
					supprimervol(dest,comp);
					strcpy(v.date,gtk_entry_get_text(GTK_ENTRY(input1)));
					F=fopen("/home/skander/Desktop/sky-travel/src/vol.txt","a+");					
					fprintf(F,"%s %s %s %s %s %s\n",v.dep,v.dest,v.comp,v.date,v.prix,v.pro);
					fclose(F);	
				}
				else if(strcmp(mes,"Depart")==0)
				{	
					supprimervol(dest,comp);
					strcpy(v.dep,gtk_entry_get_text(GTK_ENTRY(input1)));
					F=fopen("/home/skander/Desktop/sky-travel/src/vol.txt","a+");					
					fprintf(F,"%s %s %s %s %s %s\n",v.dep,v.dest,v.comp,v.date,v.prix,v.pro);
					fclose(F);	
				}
				else if(strcmp(mes,"Promotion")==0)
				{	
					supprimervol(dest,comp);
					strcpy(v.pro,gtk_entry_get_text(GTK_ENTRY(input1)));
					F=fopen("/home/skander/Desktop/sky-travel/src/vol.txt","a+");					
					fprintf(F,"%s %s %s %s %s %s\n",v.dep,v.dest,v.comp,v.date,v.prix,v.pro);
					fclose(F);	
				}
				else 
				{	
					supprimervol(dest,comp);
					strcpy(v.prix,gtk_entry_get_text(GTK_ENTRY(input1)));
					F=fopen("/home/skander/Desktop/sky-travel/src/vol.txt","a+");					
					fprintf(F,"%s %s %s %s %s %s\n",v.dep,v.dest,v.comp,v.date,v.prix,v.pro);
					fclose(F);	
				}
	
			gtk_widget_destroy(window19);
			window6=create_interface6();
			gtk_widget_show(window6);
			ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
			fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
			output1=lookup_widget(window6,"label62");
			output2=lookup_widget(window6,"label61");
			output3=lookup_widget(window6,"label57");
			output4=lookup_widget(window6,"label58");
			output5=lookup_widget(window6,"label59");
			gtk_label_set_text(GTK_LABEL(output1),n.nom);
			gtk_label_set_text(GTK_LABEL(output2),n.login);
			gtk_label_set_text(GTK_LABEL(output3),n.email);
			gtk_label_set_text(GTK_LABEL(output4),n.cin);
			gtk_label_set_text(GTK_LABEL(output5),n.num);
			gtk_widget_show(window6);
			fclose(ftemp);

			}
			else
			{
				strcpy(erreur,"Ce vol n'existe pas");
				gtk_label_set_text(GTK_LABEL(output6),erreur);
			}

			
		
     
	}
	fclose(f);

	




}


void
on_buttonafmvcat_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window19,*input1,*input2,*output1,*output2,*output3,*output4,*output5,*output6,*output7;
	FILE*f;
	vol v;
	char comp[50],dest[50],erreur[50];
	int test=0;
	strcpy(erreur,"");
	window19=lookup_widget(button,"interface19");
	input1=lookup_widget(window19,"entry35");
	input2=lookup_widget(window19,"entry36");
	output1=lookup_widget(window19,"label733");
	output2=lookup_widget(window19,"label734");
	output3=lookup_widget(window19,"label735");
	output4=lookup_widget(window19,"label736");
	output5=lookup_widget(window19,"label737");
	output6=lookup_widget(window19,"label738");
	output7=lookup_widget(window19,"label726");
	strcpy(comp,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(dest,gtk_entry_get_text(GTK_ENTRY(input1)));
	f=fopen("/home/skander/Desktop/sky-travel/src/vol.txt","r");
	while(fscanf(f,"%s %s %s %s %s %s\n",v.dep,v.dest,v.comp,v.date,v.prix,v.pro)!=EOF)
	{
			if(strcmp(dest,v.dest)==0 && strcmp(comp,v.comp)==0)
				{	gtk_label_set_text(GTK_LABEL(output7),erreur);
					test=1;
					gtk_label_set_text(GTK_LABEL(output1),v.dep);
					gtk_label_set_text(GTK_LABEL(output2),v.dest);
					gtk_label_set_text(GTK_LABEL(output3),v.comp);
					gtk_label_set_text(GTK_LABEL(output4),v.date);
					gtk_label_set_text(GTK_LABEL(output5),v.prix);
					gtk_label_set_text(GTK_LABEL(output6),v.pro);
					
				}
			
	}
	fclose(f);
	if (test==0)
	{	
		strcpy(erreur,"Ce vol n'existe pas");
		gtk_label_set_text(GTK_LABEL(output7),erreur);
	}
				
                                              
}


void
on_buttoncajhcat_clicked (GtkWidget *button,gpointer user_data)
{
	hotel v;
	FILE*f;
	FILE*ftemp;
	nouveau n;
	GtkWidget *window17,*window6,*input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*input11,*input12,*input13,*input14,*input15,*output1,*output2,*output3,*output4,*output5;
	window6=lookup_widget(button,"interface6");
	window17=lookup_widget(button,"interface20");
	input1=lookup_widget(window17,"entry38");
	input2=lookup_widget(window17,"entry43");
	input3=lookup_widget(window17,"entry52");
	input4=lookup_widget(window17,"spinbutton1");
	input5=lookup_widget(window17,"spinbutton2");
	input6=lookup_widget(window17,"spinbutton3");
	input7=lookup_widget(window17,"spinbutton12");
	input8=lookup_widget(window17,"spinbutton4");
	input9=lookup_widget(window17,"spinbutton11");
	input10=lookup_widget(window17,"spinbutton10");
	input11=lookup_widget(window17,"spinbutton9");
	input12=lookup_widget(window17,"spinbutton8");
	input13=lookup_widget(window17,"spinbutton6");
	input14=lookup_widget(window17,"spinbutton7");
	input15=lookup_widget(window17,"spinbutton5");
	strcpy(v.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(v.lieu,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(v.nbr_etoile,gtk_entry_get_text(GTK_ENTRY(input3)));
	v.sing.disp=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
	v.doub.disp=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
	v.swe.disp=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
	v.swe.prix_pc=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
	v.sing.prix_pd=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
	v.sing.prix_dp=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
	v.sing.prix_pc=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input10));
	v.doub.prix_pd=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input11));
	v.doub.prix_dp=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input12));
	v.doub.prix_pc=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input13));
	v.swe.prix_pd=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input14));
	v.swe.prix_dp=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input15));
	ajouter_hotel(v);
	gtk_widget_destroy(window17);
	window6=create_interface6();
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(ftemp);
}


void
on_buttonrcahjcat_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window19,*output1,*output2,*output3,*output4,*output5;
	FILE*ftemp;
	nouveau n;
	window6=lookup_widget(button,"interface6");
	window19=lookup_widget(button,"interface20");
	gtk_widget_destroy(window19);
	window6=create_interface6();
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(ftemp);
}


void
on_buttoncshcat_clicked (GtkWidget *button, gpointer user_data)
{
	hotel h;
	char erreur[50],lieu[50],nom[50];
	nouveau n;
	FILE*ftemp;
	FILE*f;
	strcpy(erreur,"");
   	GtkWidget *window18,*window6,*input1,*input2,*output1,*output2,*output3,*output4,*output5,*output6;
	window6=lookup_widget(button,"interface6");
	window18=lookup_widget(button,"interface21");
	output6=lookup_widget(window18,"label793");
	input1=lookup_widget(window18,"entry53");
	input2=lookup_widget(window18,"entry54");
	strcpy(lieu,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
	f=fopen("/home/skander/Desktop/sky-travel/src/hotel.txt","r");
	while(fscanf(f,"%s %s %s  %d %d %d %d %d %d %d %d %d %d %d %d\n",h.nom,h.lieu,h.nbr_etoile,&h.sing.disp,&h.sing.prix_pd,&h.sing.prix_pc,&h.sing.prix_dp,&h.doub.disp,&h.doub.prix_pd,&h.doub.prix_pc,&h.doub.prix_dp,&h.swe.disp,&h.swe.prix_pd,&h.swe.prix_pc,&h.swe.prix_dp)!=EOF)
	{
			if(strcmp(lieu,h.lieu)==0 && strcmp(nom,h.nom)==0)
				{	gtk_label_set_text(GTK_LABEL(output6),erreur);
					supprimerhotel(h.lieu,h.nom);
					gtk_widget_destroy(window18);
					window6=create_interface6();
					gtk_widget_show(window6);
					ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
					fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
					output1=lookup_widget(window6,"label62");
					output2=lookup_widget(window6,"label61");
					output3=lookup_widget(window6,"label57");
					output4=lookup_widget(window6,"label58");
					output5=lookup_widget(window6,"label59");
					gtk_label_set_text(GTK_LABEL(output1),n.nom);
					gtk_label_set_text(GTK_LABEL(output2),n.login);
					gtk_label_set_text(GTK_LABEL(output3),n.email);
					gtk_label_set_text(GTK_LABEL(output4),n.cin);
					gtk_label_set_text(GTK_LABEL(output5),n.num);
					gtk_widget_show(window6);
					fclose(ftemp);

				}
			else
			{
				strcpy(erreur,"Cet hotel n'existe pas");
				gtk_label_set_text(GTK_LABEL(output6),erreur);
			}
	}
	fclose(f);
}


void
on_buttonrshcat_clicked (GtkWidget *button, gpointer user_data)
{
	GtkWidget *window6,*window19,*output1,*output2,*output3,*output4,*output5;
	FILE*ftemp;
	nouveau n;
	window6=lookup_widget(button,"interface6");
	window19=lookup_widget(button,"interface21");
	gtk_widget_destroy(window19);
	window6=create_interface6();
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(ftemp);
}


void
on_buttonrmhcat_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window19,*output1,*output2,*output3,*output4,*output5;
	FILE*ftemp;
	nouveau n;
	window6=lookup_widget(button,"interface6");
	window19=lookup_widget(button,"interface22");
	gtk_widget_destroy(window19);
	window6=create_interface6();
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(ftemp);
}


void
on_buttonafmhcat_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window19,*input1,*input2,*output1,*output2,*output3,*output4,*output5,*output6,*output7,*output8,*output9,*output10,*output11,*output12,*output13,*output14,*output15,*output16;
	FILE*f;
	hotel h;
	char lieu[50],nom[50],erreur[50];
	int test=0;
	strcpy(erreur,"");
	window19=lookup_widget(button,"interface22");
	input1=lookup_widget(window19,"entry56");
	input2=lookup_widget(window19,"entry55");
	output1=lookup_widget(window19,"label812");
	output2=lookup_widget(window19,"label813");
	output3=lookup_widget(window19,"label814");
	output4=lookup_widget(window19,"spinbutton14");
	output5=lookup_widget(window19,"spinbutton15");
	output6=lookup_widget(window19,"spinbutton16");
	output7=lookup_widget(window19,"spinbutton17");
	output8=lookup_widget(window19,"spinbutton18");
	output9=lookup_widget(window19,"spinbutton19");
	output10=lookup_widget(window19,"spinbutton20");
	output11=lookup_widget(window19,"spinbutton21");
	output12=lookup_widget(window19,"spinbutton22");
	output13=lookup_widget(window19,"spinbutton23");
	output14=lookup_widget(window19,"spinbutton24");
	output15=lookup_widget(window19,"spinbutton25");
	output16=lookup_widget(window19,"label794");
	strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(lieu,gtk_entry_get_text(GTK_ENTRY(input1)));
	f=fopen("/home/skander/Desktop/sky-travel/src/hotel.txt","r");
	while(fscanf(f,"%s %s %s %d %d %d %d %d %d %d %d %d %d %d %d\n",h.nom,h.lieu,h.nbr_etoile,&h.sing.disp,&h.sing.prix_pd,&h.sing.prix_pc,&h.sing.prix_dp,&h.doub.disp,&h.doub.prix_pd,&h.doub.prix_pc,&h.doub.prix_dp,&h.swe.disp,&h.swe.prix_pd,&h.swe.prix_pc,&h.swe.prix_dp)!=EOF)
	{
			if(strcmp(lieu,h.lieu)==0 && strcmp(nom,h.nom)==0)
				{	gtk_label_set_text(GTK_LABEL(output16),erreur);
					test=1;
					gtk_label_set_text(GTK_LABEL(output1),h.nom);
					gtk_label_set_text(GTK_LABEL(output2),h.lieu);
					gtk_label_set_text(GTK_LABEL(output3),h.nbr_etoile);
					gtk_spin_button_set_value(GTK_SPIN_BUTTON(output4),h.sing.disp);
					gtk_spin_button_set_value(GTK_SPIN_BUTTON(output5),h.doub.disp);
					gtk_spin_button_set_value(GTK_SPIN_BUTTON(output6),h.swe.disp);
					gtk_spin_button_set_value(GTK_SPIN_BUTTON(output7),h.sing.prix_pd);
					gtk_spin_button_set_value(GTK_SPIN_BUTTON(output8),h.doub.prix_pd);
					gtk_spin_button_set_value(GTK_SPIN_BUTTON(output9),h.swe.prix_pd);
					gtk_spin_button_set_value(GTK_SPIN_BUTTON(output10),h.sing.prix_dp);
					gtk_spin_button_set_value(GTK_SPIN_BUTTON(output11),h.doub.prix_dp);
					gtk_spin_button_set_value(GTK_SPIN_BUTTON(output12),h.swe.prix_dp);
					gtk_spin_button_set_value(GTK_SPIN_BUTTON(output13),h.sing.prix_pc);
					gtk_spin_button_set_value(GTK_SPIN_BUTTON(output14),h.doub.prix_pc);
					gtk_spin_button_set_value(GTK_SPIN_BUTTON(output15),h.swe.prix_pc);
					
				}
			
	}
	fclose(f);
	if (test==0)
	{	
		strcpy(erreur,"Cet hotel n'existe pas");
		gtk_label_set_text(GTK_LABEL(output16),erreur);
	}
				
}


void
on_buttoncmhcat_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window19,*window6,*combobox4,*combobox5,*input1,*input2,*input3,*input4,*output1,*output2,*output3,*output4,*output5,*output6;	
	char mes[50],mes1[50],erreur[50];
	nouveau n;
	char nom[50],lieu[50];
	FILE*f;
	FILE*ftemp;
	hotel h;
	strcpy(erreur,"");
	window6=lookup_widget(button,"interface6");
	window19=lookup_widget(button,"interface22");
	combobox5=lookup_widget(window19,"combobox209");
	input1=lookup_widget(window19,"entry57");
	input2=lookup_widget(window19,"entry55");
	input3=lookup_widget(window19,"entry56");
	input4=lookup_widget(window19,"spinbutton13");
	output6=lookup_widget(window19,"label794");
	strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(lieu,gtk_entry_get_text(GTK_ENTRY(input3)));
	
	f=fopen("/home/skander/Desktop/sky-travel/src/hotel.txt","r");
	while(fscanf(f,"%s %s %s %d %d %d %d %d %d %d %d %d %d %d %d\n",h.nom,h.lieu,h.nbr_etoile,&h.sing.disp,&h.sing.prix_pd,&h.sing.prix_pc,&h.sing.prix_dp,&h.doub.disp,&h.doub.prix_pd,&h.doub.prix_pc,&h.doub.prix_dp,&h.swe.disp,&h.swe.prix_pd,&h.swe.prix_pc,&h.swe.prix_dp)!=EOF)
	{		gtk_label_set_text(GTK_LABEL(output6),erreur);
			if(strcmp(nom,h.nom)==0 && strcmp(lieu,h.lieu)==0)

			{	
				strcpy(mes1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)));
				
				
				if(strcmp(mes1,"Nom")==0)
				{
					supprimerhotel(lieu,nom);
					strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
					ajouter_hotel(h);				
				}
				else if(strcmp(mes1,"Lieu")==0)
				{	
					supprimerhotel(lieu,nom);
					strcpy(h.lieu,gtk_entry_get_text(GTK_ENTRY(input1)));
					ajouter_hotel(h);		
				}
				else if(strcmp(mes1,"Nbr etoile")==0)
								     	                                				{                                                                      
					supprimerhotel(lieu,nom);
					strcpy(h.nbr_etoile,gtk_entry_get_text(GTK_ENTRY(input1)));
					ajouter_hotel(h);
				}  
				else if(strcmp(mes1,"Nbr sing disp")==0)
				{
					supprimerhotel(lieu,nom);
					h.sing.disp=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
					ajouter_hotel(h);				
				}
				else if(strcmp(mes1,"Nbr doub disp")==0)
				{
					supprimerhotel(lieu,nom);
					h.doub.disp=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
					ajouter_hotel(h);				
				}
				else if(strcmp(mes1,"Nbr sweet disp")==0)
				{
					supprimerhotel(lieu,nom);
					h.swe.disp=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
					ajouter_hotel(h);				
				}
				else if(strcmp(mes1,"Prix sing petit dej")==0)
				{
					supprimerhotel(lieu,nom);
					h.sing.prix_pd=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
					ajouter_hotel(h);				
				}
				else if(strcmp(mes1,"Prix doub petit dej")==0)
				{
					supprimerhotel(lieu,nom);
					h.doub.prix_pd=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
					ajouter_hotel(h);				
				}
				else if(strcmp(mes1,"Prix sweet petit dej")==0)
				{
					supprimerhotel(lieu,nom);
					h.swe.prix_pd=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
					ajouter_hotel(h);				
				}
				else if(strcmp(mes1,"Prix sing demi pension")==0)
				{
					supprimerhotel(lieu,nom);
					h.sing.prix_dp=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
					ajouter_hotel(h);				
				}
				else if(strcmp(mes1,"Prix doub demi pension")==0)
				{
					supprimerhotel(lieu,nom);
					h.doub.prix_dp=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
					ajouter_hotel(h);				
				}
				else if(strcmp(mes1,"Prix sweet demi pension")==0)
				{
					supprimerhotel(lieu,nom);
					h.swe.prix_dp=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
					ajouter_hotel(h);				
				}
				else if(strcmp(mes1,"Prix sing pension complete")==0)
				{
					supprimerhotel(lieu,nom);
					h.sing.prix_pc=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
					ajouter_hotel(h);				
				}
				else if(strcmp(mes1,"Prix doub pension complete")==0)
				{
					supprimerhotel(lieu,nom);
					h.doub.prix_pc=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
					ajouter_hotel(h);				
				}
				else if(strcmp(mes1,"Prix sweet pension complete")==0)
				{
					supprimerhotel(lieu,nom);
					h.swe.prix_pc=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
					ajouter_hotel(h);				
				}
			/*gtk_widget_destroy(window19);
			window6=create_interface6();
			gtk_widget_show(window6);
			ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
			fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
			output1=lookup_widget(window6,"label62");
			output2=lookup_widget(window6,"label61");
			output3=lookup_widget(window6,"label57");
			output4=lookup_widget(window6,"label58");
			output5=lookup_widget(window6,"label59");
			gtk_label_set_text(GTK_LABEL(output1),n.nom);
			gtk_label_set_text(GTK_LABEL(output2),n.login);
			gtk_label_set_text(GTK_LABEL(output3),n.email);
			gtk_label_set_text(GTK_LABEL(output4),n.cin);
			gtk_label_set_text(GTK_LABEL(output5),n.num);
			gtk_widget_show(window6);
			fclose(ftemp);*/
/*
			}
			else
			{
				strcpy(erreur,"Cet hotel  n'existe pas");
				gtk_label_set_text(GTK_LABEL(output6),erreur);
			}

			
		
     
	}
	fclose(f);       	
}



void
on_buttonrajvocat_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window19,*output1,*output2,*output3,*output4,*output5;
	FILE*ftemp;
	nouveau n;
	window6=lookup_widget(button,"interface6");
	window19=lookup_widget(button,"interface25");
	gtk_widget_destroy(window19);
	window6=create_interface6();
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(ftemp);
}

void
on_buttonajvocat_clicked (GtkWidget *button,gpointer user_data)
{
	
	FILE*ftemp;
	nouveau n;
	voyage v;  
	GtkWidget *window17,*window6,*input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*output1,*output2,*output3,*output4,*output5;
	window6=lookup_widget(button,"interface6");
	window17=lookup_widget(button,"interface23");
	input1=lookup_widget(window17,"entry58");
	input2=lookup_widget(window17,"entry62");
	input3=lookup_widget(window17,"entry61");
	input4=lookup_widget(window17,"entry60");
	input5=lookup_widget(window17,"entry59");
	input6=lookup_widget(window17,"entry63");
	input7=lookup_widget(window17,"spinbutton26");
	input8=lookup_widget(window17,"spinbutton29");
	strcpy(v.dest,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(v.date_a,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(v.date_r,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(v.nom_hotel,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(v.type_trans,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(v.pro,gtk_entry_get_text(GTK_ENTRY(input6)));
	v.prix=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
	v.disp=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
	ajoutervoyage(v);
	gtk_widget_destroy( window17);
	window6=create_interface6();
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(ftemp);
		
}

void
on_buttonsvocat_clicked (GtkWidget *button,gpointer user_data)
{
	voyage v;
	char erreur[50],date[50],dest[50];
	nouveau n;
	FILE*ftemp;
	FILE*f;
	strcpy(erreur,"");
   	GtkWidget *window18,*window6,*input1,*input2,*output1,*output2,*output3,*output4,*output5,*output6;
	window6=lookup_widget(button,"interface6");
	window18=lookup_widget(button,"interface24");
	output6=lookup_widget(window18,"label823");
	input1=lookup_widget(window18,"entry64");
	input2=lookup_widget(window18,"entry65");
	strcpy(date,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(dest,gtk_entry_get_text(GTK_ENTRY(input1)));
	f=fopen("/home/skander/Desktop/sky-travel/src/voyage.txt","r");    
	while(fscanf(f,"%s %s %s %s %s %d %d %s\n",v.dest,v.date_a,v.date_r,v.nom_hotel,v.type_trans,&v.prix,&v.disp,v.pro)!=EOF)
	{
			if(strcmp(date,v.date_a)==0 && strcmp(dest,v.dest)==0)
				{	gtk_label_set_text(GTK_LABEL(output6),erreur);
					supprimervoyage(dest,date);
					gtk_widget_destroy(window18);
					window6=create_interface6();
					gtk_widget_show(window6);
					ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
					fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
					output1=lookup_widget(window6,"label62");
					output2=lookup_widget(window6,"label61");
					output3=lookup_widget(window6,"label57");
					output4=lookup_widget(window6,"label58");
					output5=lookup_widget(window6,"label59");
					gtk_label_set_text(GTK_LABEL(output1),n.nom);
					gtk_label_set_text(GTK_LABEL(output2),n.login);
					gtk_label_set_text(GTK_LABEL(output3),n.email);
					gtk_label_set_text(GTK_LABEL(output4),n.cin);
					gtk_label_set_text(GTK_LABEL(output5),n.num);
					gtk_widget_show(window6);
					fclose(ftemp);

				}
			else
			{
				strcpy(erreur,"Ce voyage n'existe pas");
				gtk_label_set_text(GTK_LABEL(output6),erreur);
			}
	}
	fclose(f);
}


void
on_buttonrvocat_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window19,*output1,*output2,*output3,*output4,*output5;
	FILE*ftemp;
	nouveau n;
	window6=lookup_widget(button,"interface6");
	window19=lookup_widget(button,"interface24");
	gtk_widget_destroy(window19);
	window6=create_interface6();
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(ftemp);
}


void
on_buttonafvocat_clicked (GtkWidget *button,gpointer user_data)
{	
	GtkWidget *window19,*input1,*input2,*output1,*output2,*output3,*output4,*output5,*output6,*output7,*output8,*output9;
	voyage v;
	FILE*f;
	char dest[50],date[50],erreur[50];
	int test=0;
	strcpy(erreur,"");
	window19=lookup_widget(button,"interface25");
	input1=lookup_widget(window19,"entry66");
	input2=lookup_widget(window19,"entry67");
	output1=lookup_widget(window19,"label835");
	output2=lookup_widget(window19,"label836");
	output3=lookup_widget(window19,"label837");
	output4=lookup_widget(window19,"label838");
	output5=lookup_widget(window19,"label839");
	output6=lookup_widget(window19,"label840");
	output7=lookup_widget(window19,"spinbutton27");
	output9=lookup_widget(window19,"spinbutton30");
	output8=lookup_widget(window19,"label841");
	strcpy(date,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(dest,gtk_entry_get_text(GTK_ENTRY(input1)));
	f=fopen("/home/skander/Desktop/sky-travel/src/voyage.txt","r");
	while(fscanf(f,"%s %s %s %s %s %d %d %s\n",v.dest,v.date_a,v.date_r,v.nom_hotel,v.type_trans,&v.prix,&v.disp,v.pro)!=EOF)
	{		
			if(strcmp(dest,v.dest)==0 && strcmp(date,v.date_a)==0)
				{	test=1;
					gtk_label_set_text(GTK_LABEL(output8),erreur);
					gtk_label_set_text(GTK_LABEL(output1),v.dest);
					gtk_label_set_text(GTK_LABEL(output2),v.date_a);
					gtk_label_set_text(GTK_LABEL(output3),v.date_r);
					gtk_label_set_text(GTK_LABEL(output4),v.nom_hotel);
					gtk_label_set_text(GTK_LABEL(output5),v.type_trans);
					gtk_label_set_text(GTK_LABEL(output6),v.pro);
					gtk_spin_button_set_value(GTK_SPIN_BUTTON(output7),v.prix);
					gtk_spin_button_set_value(GTK_SPIN_BUTTON(output9),v.disp);
					
					
				}
			
	}
	fclose(f);
	if (test==0)
	{	
		strcpy(erreur,"Ce voyage n'existe pas");
		gtk_label_set_text(GTK_LABEL(output8),erreur);
	}
}


void
on_buttonrmvocat_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window19,*output1,*output2,*output3,*output4,*output5;
	FILE*ftemp;
	nouveau n;
	window6=lookup_widget(button,"interface6");
	window19=lookup_widget(button,"interface25");
	gtk_widget_destroy(window19);
	window6=create_interface6();
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label66");
	output2=lookup_widget(window6,"label67");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(ftemp);
}


void
on_buttoncmovocat_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window19,*combobox4,*input1,*input2,*input3,*input4,*output1,*output2,*output3,*output4,*output5,*output6;	
	char mes[50],erreur[50];
	nouveau n;
	char dest[50],date[50];
	FILE*f;
	voyage v;
	strcpy(erreur,"");
	window19=lookup_widget(button,"interface25");
	combobox4=lookup_widget(window19,"combobox210");
	input4=lookup_widget(window19,"spinbutton28");
	input1=lookup_widget(window19,"entry68");
	input2=lookup_widget(window19,"entry66");
	input3=lookup_widget(window19,"entry67");
	output6=lookup_widget(window19,"label841");
	strcpy(dest,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(date,gtk_entry_get_text(GTK_ENTRY(input3)));
	f=fopen("/home/skander/Desktop/sky-travel/src/voyage.txt","r");
	while(fscanf(f,"%s %s %s %s %s %d %d %s\n",v.dest,v.date_a,v.date_r,v.nom_hotel,v.type_trans,&v.prix,&v.disp,v.pro)!=EOF)
	{		
			if(strcmp(dest,v.dest)==0 && strcmp(date,v.date_a)==0)

			{	gtk_label_set_text(GTK_LABEL(output6),erreur);
				strcpy(mes,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4)));
				if(strcmp(mes,"Destination")==0)
				{	
					supprimervoyage(dest,date);
					strcpy(v.dest,gtk_entry_get_text(GTK_ENTRY(input1)));
					ajoutervoyage(v);
									
				}
				else if(strcmp(mes,"Nom hotel")==0)
				{	
					supprimervoyage(dest,date);
					strcpy(v.nom_hotel,gtk_entry_get_text(GTK_ENTRY(input1)));
					ajoutervoyage(v);	
				}
				else if(strcmp(mes,"Date allée")==0)
				{	
					supprimervoyage(dest,date);
					strcpy(v.date_a,gtk_entry_get_text(GTK_ENTRY(input1)));
					ajoutervoyage(v);
				}
				else if(strcmp(mes,"Date retour")==0)
				{	
					supprimervoyage(dest,date);
					strcpy(v.date_r,gtk_entry_get_text(GTK_ENTRY(input1)));
					ajoutervoyage(v);
						
				}
				else if(strcmp(mes,"Promotion")==0)
				{	
					supprimervoyage(dest,date);
					strcpy(v.pro,gtk_entry_get_text(GTK_ENTRY(input1)));
					ajoutervoyage(v);	
				}
				else if(strcmp(mes,"Type transport")==0)
				{	
					supprimervoyage(dest,date);
					strcpy(v.type_trans,gtk_entry_get_text(GTK_ENTRY(input1)));
					ajoutervoyage(v);	
				}
				else if(strcmp(mes,"Disponible")==0)
				{	
					supprimervoyage(dest,date);
					v.disp=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
					ajoutervoyage(v);	
				}								
				else 
				{	
					supprimervoyage(dest,date);
					v.prix=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
					ajoutervoyage(v);	
				}
	
			

			}
			else
			{
				strcpy(erreur,"Ce voyage n'existe pas");
				gtk_label_set_text(GTK_LABEL(output6),erreur);
			}

			
		
     
	}
	fclose(f);
}


void on_buttonconfmag_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window9,*window4,*combobox2,*input1,*output1,*output2,*output3,*output4,*output5;	
	char mes[50];
	nouveau n;
	FILE*f;
	window4=lookup_widget(button,"interface6");
	window9=lookup_widget(button,"interface26");
	combobox2=lookup_widget(window9,"combobox6");
	input1=lookup_widget(window9,"entryma");
	strcpy(mes,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
	if(strcmp(mes,"nom")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"login")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.login,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"password")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.password,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"email")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.email,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"cin")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.num,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	gtk_widget_destroy(window9);
	window4=lookup_widget(button,"interface6");
	window4=create_interface6();
	output1=lookup_widget(window4,"label62");
	output2=lookup_widget(window4,"label61");
	output3=lookup_widget(window4,"label57");
	output4=lookup_widget(window4,"label58");
	output5=lookup_widget(window4,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);		
	gtk_widget_show(window4);
}


void on_buttonretmag_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window26,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	window26=lookup_widget(button,"interface26");
	window6=lookup_widget(button,"interface6");
	gtk_widget_destroy(window26);	
	window6=create_interface6();
	fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(f);
}


void on_buttonconfajc_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window27,*input1,*input2,*input3,*input4,*input5,*input6,*output1,*output2,*output3,*output4,*output5;
	nouveau n;
	FILE*f;
	window6=lookup_widget(button,"interface6");	
	window27=lookup_widget(button,"interface27");
	input1=lookup_widget(window27,"entryac1");
	input2=lookup_widget(window27,"entryac2");
	input3=lookup_widget(window27,"entryac3");
	input4=lookup_widget(window27,"entryac4");
	input5=lookup_widget(window27,"entryac5");
	input6=lookup_widget(window27,"entryac6");
	strcpy(n.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(n.login,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(n.password,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(n.email,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(n.cin,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(n.num,gtk_entry_get_text(GTK_ENTRY(input6)));
	n.id=1;
	ajouter(n);
	ajouter_client(n);
	gtk_widget_destroy(window27);
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	window6=create_interface6();
	fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
}


void on_buttonretajgc_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window27,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	window27=lookup_widget(button,"interface27");
	window6=lookup_widget(button,"interface6");
	gtk_widget_destroy(window27);	
	window6=create_interface6();
	fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(f);
}


void on_buttonlogmc_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window12,*window13,*output1,*input1,*input2,*input3,*input4,*input5,*input6,*input7;
	FILE*f;
	FILE*ftemp;
	int verf=0;
	char log[50],pass[50],mes[50];
	nouveau n;
	input6=lookup_widget(button,"entrylogmc");
	input7=lookup_widget(button,"entrypwmc");
	window12=lookup_widget(button,"interface28");
	window13=lookup_widget(button,"interface29");
	strcpy(log,gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(pass,gtk_entry_get_text(GTK_ENTRY(input7)));
	output1=lookup_widget(window12,"labelerreur1");
	verf=verif(log,pass);
	if(verf==1)	
	{	
		f=fopen("/home/skander/Desktop/sky-travel/src/clients.txt","r");
		ftemp=fopen("/home/skander/Desktop/sky-travel/src/am.txt","w");
		while(fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id)!=EOF)
		{
			if(strcmp(log,n.login)==0 && strcmp(pass,n.password)==0)
			{
				fprintf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
			}
		}
		fclose(f);
		fclose(ftemp);
		window13=create_interface29();
		gtk_widget_destroy(window12);
		gtk_widget_show(window13);
	}	
	else
	{
		strcpy(mes,"Cet agent n'existe pas");
		gtk_label_set_text(GTK_LABEL(output1),mes);		
	}	
}


void on_buttonretmc_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window28,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	window28=lookup_widget(button,"interface28");
	window6=lookup_widget(button,"interface6");
	gtk_widget_destroy(window28);	
	window6=create_interface6();
	fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(f);
}


void on_buttonconfmodc_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window29,*window6,*combobox2,*input1,*output1,*output2,*output3,*output4,*output5;	
	char mes[50];
	nouveau n;
	FILE*f;
	window6=lookup_widget(button,"interface6");
	window29=lookup_widget(button,"interface29");
	combobox2=lookup_widget(window29,"combobox7");
	input1=lookup_widget(window29,"entrymodc");
	strcpy(mes,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
	if(strcmp(mes,"nom")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/am.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		supprimer_client(n.login,n.password);
		strcpy(n.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		ajouter_client(n);
		remove("/home/skander/Desktop/sky-travel/src/am.txt");
	}
	else if(strcmp(mes,"login")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/am.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		supprimer_client(n.login,n.password);
		strcpy(n.login,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		ajouter_client(n);
		remove("/home/skander/Desktop/sky-travel/src/am.txt");
	}
	else if(strcmp(mes,"password")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/am.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		supprimer_client(n.login,n.password);
		strcpy(n.password,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		ajouter_client(n);
		remove("/home/skander/Desktop/sky-travel/src/am.txt");
	}
	else if(strcmp(mes,"email")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/am.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		supprimer_client(n.login,n.password);
		strcpy(n.email,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		ajouter_client(n);
		remove("/home/skander/Desktop/sky-travel/src/am.txt");
	}
	else if(strcmp(mes,"cin")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/am.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		supprimer_client(n.login,n.password);
		strcpy(n.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		ajouter_client(n);
		remove("/home/skander/Desktop/sky-travel/src/am.txt");
	}
	else
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/am.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		supprimer_client(n.login,n.password);
		strcpy(n.num,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		ajouter_client(n);
		remove("/home/skander/Desktop/sky-travel/src/am.txt");
	}
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(f,"%s %s %s %s %s %s",n.nom,n.login,n.password,n.email,n.cin,n.num);
	gtk_widget_destroy(window29);
	window6=lookup_widget(button,"interface6");
	window6=create_interface6();
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);		
	gtk_widget_show(window6);
}


void on_buttonretmodc_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window28,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	window28=lookup_widget(button,"interface29");
	window6=lookup_widget(button,"interface6");
	gtk_widget_destroy(window28);	
	window6=create_interface6();
	fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(f);
}


void on_buttonconfsuppc_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window4,*window11,*output1,*output2,*output3,*output4,*output5,*input6,*input7;
	FILE*f;
	int verf=0;
	char log[50],pass[50],mes[50];
	nouveau n;
	input6=lookup_widget(button,"entrysupcc1");
	input7=lookup_widget(button,"entrysupcc2");
	window11=lookup_widget(button,"interface30");
	window4=lookup_widget(button,"interface6");
	strcpy(log,gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(pass,gtk_entry_get_text(GTK_ENTRY(input7)));
	output1=lookup_widget(window11,"labelerreur2");
	verf=verif(log,pass);
	if(verf==1)	
	{	
		supprimer(log,pass);
		supprimer_client(log,pass);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		window11=lookup_widget(button,"interface30");	
		window4=lookup_widget(button,"interface6");
		gtk_widget_destroy(window11);	
		window4=create_interface6();
		fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		output1=lookup_widget(window4,"label62");
		output2=lookup_widget(window4,"label61");
		output3=lookup_widget(window4,"label57");
		output4=lookup_widget(window4,"label58");
		output5=lookup_widget(window4,"label59");
		gtk_label_set_text(GTK_LABEL(output1),n.nom);
		gtk_label_set_text(GTK_LABEL(output2),n.login);
		gtk_label_set_text(GTK_LABEL(output3),n.email);
		gtk_label_set_text(GTK_LABEL(output4),n.cin);
		gtk_label_set_text(GTK_LABEL(output5),n.num);
		gtk_widget_show(window4);
		fclose(f);
	}	
	else
	{
		strcpy(mes,"Cet utilisateur n'existe pas");
		gtk_label_set_text(GTK_LABEL(output1),mes);		
	}	
}


void on_buttonretsuppc_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window28,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	window28=lookup_widget(button,"interface30");
	window6=lookup_widget(button,"interface6");
	gtk_widget_destroy(window28);	
	window6=create_interface6();
	fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(f);
}


void on_buttoncmcp_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window9,*window4,*combobox2,*input1,*output1,*output2,*output3,*output4,*output5;	
	char mes[50];
	nouveau n;
	FILE*f;
	window4=lookup_widget(button,"interface5");
	window9=lookup_widget(button,"interface31");
	combobox2=lookup_widget(window9,"combobox8");
	input1=lookup_widget(window9,"entrymcp");
	strcpy(mes,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
	if(strcmp(mes,"nom")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"login")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.login,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"password")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.password,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"email")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.email,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"cin")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.num,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	gtk_widget_destroy(window9);
	window4=lookup_widget(button,"interface5");
	window4=create_interface5();
	output1=lookup_widget(window4,"label47");
	output2=lookup_widget(window4,"label46");
	output3=lookup_widget(window4,"label42");
	output4=lookup_widget(window4,"label43");
	output5=lookup_widget(window4,"label44");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);		
	gtk_widget_show(window4);
}


void on_buttonrmcp_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window5,*window31,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	window31=lookup_widget(button,"interface31");
	window5=lookup_widget(button,"interface5");
	gtk_widget_destroy(window31);	
	window5=create_interface5();
	fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window5,"label47");
	output2=lookup_widget(window5,"label46");
	output3=lookup_widget(window5,"label42");
	output4=lookup_widget(window5,"label43");
	output5=lookup_widget(window5,"label44");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window5);
	fclose(f);
}


void on_buttonretutil_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window1,*window32;
	window1=lookup_widget(button,"interface1");
	window32=lookup_widget(button,"interface32");
	gtk_widget_destroy(window32);
	window1=create_interface1();
	gtk_widget_show(window1);
}


void on_buttonconfchcag_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window9,*window4,*combobox2,*input1,*output1,*output2,*output3,*output4,*output5;	
	char mes[50];
	nouveau n;
	FILE*f;
	window4=lookup_widget(button,"interface6");
	window9=lookup_widget(button,"interface33");
	combobox2=lookup_widget(window9,"combobox9");
	input1=lookup_widget(window9,"entrymodcag");
	strcpy(mes,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
	if(strcmp(mes,"nom")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"login")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.login,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"password")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.password,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"email")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.email,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else if(strcmp(mes,"cin")==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	else
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
		fscanf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
		fclose(f);
		supprimer(n.login,n.password);
		strcpy(n.num,gtk_entry_get_text(GTK_ENTRY(input1)));
		ajouter(n);
		f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","w");
		fprintf(f,"%s %s %s %s %s %s %d",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		fclose(f);
	}
	gtk_widget_destroy(window9);
	window4=lookup_widget(button,"interface6");
	window4=create_interface6();
	output1=lookup_widget(window4,"label62");
	output2=lookup_widget(window4,"label61");
	output3=lookup_widget(window4,"label57");
	output4=lookup_widget(window4,"label58");
	output5=lookup_widget(window4,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);		
	gtk_widget_show(window4);
}

void on_buttonretouuur_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*window33,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	window6=lookup_widget(button,"interface6");
	window33=lookup_widget(button,"interface33");
	gtk_widget_destroy(window33);
	window6=create_interface6();
	output1=lookup_widget(window6,"label62");
	output2=lookup_widget(window6,"label61");
	output3=lookup_widget(window6,"label57");
	output4=lookup_widget(window6,"label58");
	output5=lookup_widget(window6,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(f);
}


void on_buttonalc_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window6,*treeview3;
	window6=lookup_widget(button,"interface6");
	treeview3=lookup_widget(button,"treeview4");
	afficher_clients(treeview3);
}


void on_buttonAffCatPromo_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window1,*combobox,*treeview;
	window1=lookup_widget(button,"interface32");
	treeview=lookup_widget(button,"treeview6");
	combobox=lookup_widget(button,"combobox999");
	if(strcmp("Voyage Organisé",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		afficher_vop(treeview);
	}
	else if(strcmp("Vol",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		afficher_volp(treeview);
	}
	else if(strcmp("Hébergement",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		afficher_hebp(treeview);
	}
	else if(strcmp("Location Voiture",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
		afficher_lvp(treeview);
	}
	
}


void
on_buttonCc_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	window1=lookup_widget(button,"interface1");
	window2=lookup_widget(button,"interface32");
	gtk_widget_destroy(window1);
	window2=create_interface32();
	gtk_widget_show(window2);
}


void
on_buttonAffiRes_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*treeview,*combobox1,*combobox2;
	FILE*f;
	voyage vo;
	vol v;
	lv lv;
	hotel h;
	window1=lookup_widget(button,"interface3");
	treeview=lookup_widget(window1,"treeview1");
	combobox1=lookup_widget(window1,"comboboxtype");
	combobox2=lookup_widget(window1,"comboboxchoix");
	if(strcmp("Voyage Organisé",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
	{
		afficher_vo(treeview);
		f=fopen("/home/skander/Desktop/sky-travel/src/voyage.txt","r");
		while(fscanf(f,"%s %s %s %s %s %d %d %s %d\n",vo.dest,vo.date_a,vo.date_r,vo.nom_hotel,vo.type_trans,&vo.prix,&vo.disp,vo.pro,&vo.id)!=EOF)
		{
			gtk_combo_box_append_text(GTK_COMBO_BOX(combobox2),vo.dest);
		}
		fclose(f);
	}
	else if(strcmp("Vol",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
	{
		afficher_vol(treeview);
		f=fopen("/home/skander/Desktop/sky-travel/src/vol.txt","r");
		while(fscanf(f,"%s %s %s %s %s %s %d\n",v.dep,v.dest,v.comp,v.date,v.prix,v.pro,&v.id)!=EOF)
		{
			gtk_combo_box_append_text(GTK_COMBO_BOX(combobox2),v.dest);
		}
		fclose(f);
	}
	else if(strcmp("Hébergement",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
	{
		afficher_heb(treeview);
		f=fopen("/home/skander/Desktop/sky-travel/src/hotel.txt","r");
		while(fscanf(f,"%s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %s %d\n",h.nom,h.lieu,h.nbr_etoile,&h.sing.disp,&h.sing.prix_pd,&h.sing.prix_pc,&h.sing.prix_dp,&h.doub.disp,&h.doub.prix_pd,&h.doub.prix_pc,&h.doub.prix_dp,&h.swe.disp,&h.swe.prix_pd,&h.swe.prix_pc,&h.swe.prix_dp,h.promo,&h.id)!=EOF)
		{
			gtk_combo_box_append_text(GTK_COMBO_BOX(combobox2),h.nom);
		}
		fclose(f);
	}
	else if(strcmp("Location Voiture",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
	{
		afficher_lv(treeview);
		f=fopen("/home/skander/Desktop/sky-travel/src/lv.txt","r");
		while(fscanf(f,"%s %s %s %s %s %s %d\n",lv.type,lv.nch,lv.date_a,lv.date_r,lv.prix,lv.promo,&lv.id)!=EOF)
		{
			gtk_combo_box_append_text(GTK_COMBO_BOX(combobox2),lv.type);
		}
		fclose(f);
	}
}


void
on_buttonAr_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window5,*out6,*input45,*window1,*window2,*window3,*window4,*combobox2,*combobox1,*combobox3,*out1,*out2,*out3,*out4,*out5,*input44;
	hotel h;
	vol v;
	lv lv;
	voyage v1;
	FILE*f;
	FILE*f1;
	FILE*F;
	FILE*F1;
	FILE*g;
	FILE*G;
	FILE*G1;
	FILE*g1;
	window1=lookup_widget(button,"interface3");
	window2=lookup_widget(button,"interface34");
	window3=lookup_widget(button,"interface35");
	window4=lookup_widget(button,"interface37");
	window5=lookup_widget(button,"interface38");
	combobox1=lookup_widget(window1,"comboboxtype");
	combobox2=lookup_widget(window1,"comboboxchoix");
	if(strcmp("Hébergement",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
	{
		f=fopen("/home/skander/Desktop/sky-travel/src/hotel.txt","r");
		while(fscanf(f,"%s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %s %d\n",h.nom,h.lieu,h.nbr_etoile,&h.sing.disp,&h.sing.prix_pd,&h.sing.prix_pc,&h.sing.prix_dp,&h.doub.disp,&h.doub.prix_pd,&h.doub.prix_pc,&h.doub.prix_dp,&h.swe.disp,&h.swe.prix_pd,&h.swe.prix_pc,&h.swe.prix_dp,h.promo,&h.id)!=EOF)
		{
			if(strcmp(h.nom,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
			{
				gtk_widget_destroy(window1);
				window2=create_interface34();
				out1=lookup_widget(window2,"label900");
				out2=lookup_widget(window2,"label901");
				out3=lookup_widget(window2,"label902");
				gtk_label_set_text(GTK_LABEL(out1),h.nom);
				gtk_label_set_text(GTK_LABEL(out2),h.lieu);
				gtk_label_set_text(GTK_LABEL(out3),h.nbr_etoile);
				gtk_widget_show(window2);
				f1=fopen("/home/skander/Desktop/sky-travel/src/temporel.txt","w");
				fprintf(f1,"%s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %s %d\n",h.nom,h.lieu,h.nbr_etoile,h.sing.disp,h.sing.prix_pd,h.sing.prix_pc,h.sing.prix_dp,h.doub.disp,h.doub.prix_pd,h.doub.prix_pc,h.doub.prix_dp,h.swe.disp,h.swe.prix_pd,h.swe.prix_pc,h.swe.prix_dp,h.promo,h.id);
				fclose(f1);
			}
		}
		fclose(f);
	}
	else if(strcmp("Vol",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
	{
		F=fopen("/home/skander/Desktop/sky-travel/src/vol.txt","r");
		while(fscanf(F,"%s %s %s %s %s %s %d\n",v.dep,v.dest,v.comp,v.date,v.prix,v.pro,&v.id)!=EOF)
		{
			if(strcmp(v.dest,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
			{
				
				gtk_widget_destroy(window1);
				window3=create_interface35();
				out4=lookup_widget(window3,"label970");	
				gtk_label_set_text(GTK_LABEL(out4),v.dest);
				gtk_widget_show(window3);
				F1=fopen("/home/skander/Desktop/sky-travel/src/voltemporel.txt","w");
				fprintf(F1,"%s %s %s %s %s %s\n",v.dep,v.dest,v.comp,v.date,v.prix,v.pro,v.id);
				fclose(F1);
			}
		}
		fclose(F);
	}
	else if(strcmp("Voyage Organisé",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
	{
		g=fopen("/home/skander/Desktop/sky-travel/src/voyage.txt","r");
		while(fscanf(g,"%s %s %s %s %s %d %d %s %d\n",v1.dest,v1.date_a,v1.date_r,v1.nom_hotel,v1.type_trans,&v1.prix,&v1.disp,v1.pro,&v1.id)!=EOF)
		{
			if(strcmp(v1.dest,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
			{
				
				gtk_widget_destroy(window1);
				window4=create_interface37();
				out5=lookup_widget(window4,"dest");	
				gtk_label_set_text(GTK_LABEL(out5),v1.dest);
				gtk_widget_show(window4);
				g1=fopen("/home/skander/Desktop/sky-travel/src/voyagetemporel.txt","w");
				fprintf(g1,"%s %s %s %s %s %d %d %s %d\n",v1.dest,v1.date_a,v1.date_r,v1.nom_hotel,v1.type_trans,v1.prix,v1.disp,v1.pro,v1.id);
				fclose(g1);
			}
		}
		fclose(g);}
	
	
	else if(strcmp("Location Voiture",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
	{
		G=fopen("/home/skander/Desktop/sky-travel/src/lv.txt","r");
		while(fscanf(G,"%s %s %s %s %s %s %d\n",lv.type,lv.nch,lv.date_a,lv.date_r,lv.prix,lv.promo,&lv.id)!=EOF)
		{
			if(strcmp(lv.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
			{
				
				gtk_widget_destroy(window1);
				window5=create_interface38();
				out6=lookup_widget(window5,"voiture");	
				gtk_label_set_text(GTK_LABEL(out6),lv.type);
				gtk_widget_show(window5);
				G1=fopen("/home/skander/Desktop/sky-travel/src/lvtemporel.txt","w");
				fprintf(G1,"%s %s %s %s %s %s %d\n",lv.type,lv.nch,lv.date_a,lv.date_r,lv.prix,lv.promo,lv.id);
				fclose(G1);
			}
		}
		fclose(G);
	}
}


void
on_buttonret0002_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window3,*window2,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	window2=lookup_widget(button,"interface34");
	window3=lookup_widget(button,"interface3");
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	gtk_widget_destroy(window2);
	window3=create_interface3();
	gtk_widget_show(window3);
	output1=lookup_widget(window3,"label18");
	output2=lookup_widget(window3,"label19");
	output3=lookup_widget(window3,"label20");
	output4=lookup_widget(window3,"label21");
	output5=lookup_widget(window3,"label22");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);	
}


void
on_buttonAjhres_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2,*combobox1,*combobox2,*out1,*in1,*in2;
	FILE*f;
	FILE*f1;
	FILE*ftemp;
	hotel h;
	nouveau n;
	char er[50],ef[50],type_c[50],type_p[50],date_a[50],date_r[50];
	f=fopen("/home/skander/Desktop/sky-travel/src/temporel.txt","r");
	f1=fopen("/home/skander/Desktop/sky-travel/src/reservationheb.txt","a+");
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	while(fscanf(f,"%s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %s %d\n",h.nom,h.lieu,h.nbr_etoile,&h.sing.disp,&h.sing.prix_pd,&h.sing.prix_pc,&h.sing.prix_dp,&h.doub.disp,&h.doub.prix_pd,&h.doub.prix_pc,&h.doub.prix_dp,&h.swe.disp,&h.swe.prix_pd,&h.swe.prix_pc,&h.swe.prix_dp,h.promo,&h.id)!=EOF);
	window1=lookup_widget(button,"interface34");
	combobox1=lookup_widget(window1,"combobox1001");
	combobox2=lookup_widget(window1,"combobox1002");
	out1=lookup_widget(window1,"label903");
	strcpy(er,"non disponible");
	strcpy(ef,"Réservation reussite");
	in1=lookup_widget(window1,"entryAAA1");
	in2=lookup_widget(window1,"entryAAA2");
	strcpy(date_a,gtk_entry_get_text(GTK_ENTRY(in1)));
	strcpy(date_r,gtk_entry_get_text(GTK_ENTRY(in2)));
	if(strcmp("Chambre single",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
	{
		strcpy(type_c,"single");
		strcpy(type_p,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
		if(h.sing.disp==0)
			gtk_label_set_text(GTK_LABEL(out1),er);
		else
		{
			fprintf(f1,"%s %s %s %s %s %s %s %s\n",n.login,n.password,h.nom,h.nbr_etoile,type_c,type_p,date_a,date_r);
			gtk_label_set_text(GTK_LABEL(out1),ef);
		}
	}
	else if(strcmp("Chambre double",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
	{
		strcpy(type_c,"double");
		strcpy(type_p,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
		if(h.doub.disp==0)
			gtk_label_set_text(GTK_LABEL(out1),er);
		else
		{
			fprintf(f1,"%s %s %s %s %s %s %s %s\n",n.login,n.password,h.nom,h.nbr_etoile,type_c,type_p,date_a,date_r);
			gtk_label_set_text(GTK_LABEL(out1),ef);
		}
	}
	else if(strcmp("Suite",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
	{
		strcpy(type_c,"Suite");
		strcpy(type_p,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
		if(h.doub.disp==0)
			gtk_label_set_text(GTK_LABEL(out1),er);
		else
		{
			fprintf(f1,"%s %s %s %s %s %s %s %s\n",n.login,n.password,h.nom,h.nbr_etoile,type_c,type_p,date_a,date_r);
			gtk_label_set_text(GTK_LABEL(out1),ef);
		}
	}
	fclose(f);
	fclose(f1);
	fclose(ftemp);
}


void
on_buttonmr_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2,*combobox1,*combobox2,*combobox3,*combobox4;
	FILE*f1;
	FILE*f2;
	FILE*f3;
	FILE*f4;
	reshotel h;
	reslv lv;
	resvol v;
	resvoyage vo;
	window1=lookup_widget(button,"interface3");
	window2=lookup_widget(button,"interface36");
	gtk_widget_destroy(window1);
	window2=create_interface36();
	gtk_widget_show(window2);
	combobox1=lookup_widget(window2,"combobox1004");
	combobox2=lookup_widget(window2,"combobox1007");
	combobox3=lookup_widget(window2,"combobox1008");
	combobox4=lookup_widget(window2,"combobox1009");
	f1=fopen("/home/skander/Desktop/sky-travel/src/reservationheb.txt","r");
	f2=fopen("/home/skander/Desktop/sky-travel/src/reservationlv.txt","r");
	f3=fopen("/home/skander/Desktop/sky-travel/src/reservationvo.txt","r");
	f4=fopen("/home/skander/Desktop/sky-travel/src/reservationvol.txt","r");
	while(fscanf(f1,"%s %s %s %s %s %s %s %s\n",h.login,h.password,h.nom,h.nb_e,h.type_c,h.type_p,h.date_a,h.date_r)!=EOF)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(combobox1),h.nom);
	}
	while(fscanf(f2,"%s %s %s %s %s %s\n",lv.login,lv.password,lv.type,lv.nch,lv.date_a,lv.date_r)!=EOF)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(combobox2),lv.type);
	}
	while(fscanf(f3,"%s %s %s %s %s %s %d\n",vo.login,vo.password,vo.dest,vo.date_a,vo.date_r,vo.nb_ex,&vo.nb_p)!=EOF)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(combobox3),vo.dest);
	}
	while(fscanf(f4,"%s %s %s %s %s %s %s\n",v.login,v.password,v.dest,v.comp,v.type_vol,v.date_a,v.date_r)!=EOF)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(combobox4),v.dest);
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
}


void
on_buttonref1_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*combobox1,*in1,*in2;
	FILE*f1;
	reshotel h;
	char mes[50];
	nouveau n;
	FILE*ftemp;
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	window1=lookup_widget(button,"interface36");
	combobox1=lookup_widget(window1,"combobox1004");
	in1=lookup_widget(window1,"entryAA1");
	in2=lookup_widget(window1,"entryAA2");
	strcpy(mes,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
	f1=fopen("/home/skander/Desktop/sky-travel/src/reservationheb.txt","r");
	while(fscanf(f1,"%s %s %s %s %s %s %s %s\n",h.login,h.password,h.nom,h.nb_e,h.type_c,h.type_p,h.date_a,h.date_r)!=EOF)
	{
		if(strcmp(mes,h.nom)==0 && strcmp(n.login,h.login)==0)
		{
			gtk_entry_set_text(GTK_ENTRY(in1),h.date_a);
			gtk_entry_set_text(GTK_ENTRY(in2),h.date_r);
		}
	}
	fclose(f1);
	fclose(ftemp);
}


void
on_buttonModifhebcli_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*in1,*in2,*combobox1,*combobox2,*combobox3;
	FILE*f;
	FILE*f1;
	FILE*f2;
	nouveau n;
	reshotel h;
	char mes[50];
	window1=lookup_widget(button,"interface36");
	combobox1=lookup_widget(button,"combobox1004");
	combobox2=lookup_widget(window1,"combobox1005");
	combobox3=lookup_widget(window1,"combobox1006");
	in1=lookup_widget(window1,"entryAA1");
	in2=lookup_widget(window1,"entryAA2");
	f=fopen("/home/skander/Desktop/sky-travel/src/reservationheb.txt","r");
	f1=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	f2=fopen("/home/skander/Desktop/sky-travel/src/a3.txt","w");
	strcpy(mes,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
	fscanf(f1,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	while(fscanf(f,"%s %s %s %s %s %s %s %s\n",h.login,h.password,h.nom,h.nb_e,h.type_c,h.type_p,h.date_a,h.date_r)!=EOF)
	{
		if(strcmp(h.nom,mes)==0 && strcmp(n.login,h.login)==0)
			fprintf(f2,"%s %s %s %s %s %s %s %s\n",h.login,h.password,h.nom,h.nb_e,h.type_c,h.type_p,h.date_a,h.date_r);
	}
	fclose(f);
	fclose(f1);
	fscanf(f2,"%s %s %s %s %s %s %s %s\n",h.login,h.password,h.nom,h.nb_e,h.type_c,h.type_p,h.date_a,h.date_r);
	supprimer_resheb(h.login,h.nom);
	strcpy(h.date_a,gtk_entry_get_text(GTK_ENTRY(in1)));
	strcpy(h.date_r,gtk_entry_get_text(GTK_ENTRY(in2)));
	strcpy(h.type_c,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
	strcpy(h.type_p,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));
	ajouter_resheb(h);
	fclose(f2);
	remove("/home/skander/Desktop/sky-travel/src/am.3");
}


void
on_buttonref2_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*combobox1,*in1,*in2;
	FILE*f2;
	reslv lv;
	char mes[50];
	nouveau n;
	FILE*ftemp;
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	window1=lookup_widget(button,"interface36");
	combobox1=lookup_widget(window1,"combobox1007");
	in1=lookup_widget(window1,"entryAA3");
	in2=lookup_widget(window1,"entryAA4");
	strcpy(mes,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
	f2=fopen("/home/skander/Desktop/sky-travel/src/reservationlv.txt","r");
	while(fscanf(f2,"%s %s %s %s %s %s\n",lv.login,lv.password,lv.type,lv.nch,lv.date_a,lv.date_r)!=EOF)
	{
		if(strcmp(mes,lv.type)==0 && strcmp(n.login,lv.login)==0)
		{
			gtk_entry_set_text(GTK_ENTRY(in1),lv.date_a);
			gtk_entry_set_text(GTK_ENTRY(in2),lv.date_r);
		}
	}
	fclose(f2);
	fclose(ftemp);
}


void
on_buttonModiflvcli_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
	
}


void
on_buttonref3_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*in1,*in2,*in3,*in4,*spin,*combobox1;
	FILE*f3;
	char mes[50];
	resvoyage vo;
	nouveau n;
	FILE*ftemp;
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	window1=lookup_widget(button,"interface36");
	combobox1=lookup_widget(window1,"combobox1008");
	in1=lookup_widget(window1,"entryAA5");
	in2=lookup_widget(window1,"entryAA6");
	in3=lookup_widget(window1,"entryAA8");
	strcpy(mes,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
	spin=lookup_widget(window1,"spinbutton31");
	f3=fopen("/home/skander/Desktop/sky-travel/src/reservationvo.txt","r");
	while(fscanf(f3,"%s %s %s %s %s %s %d\n",vo.login,vo.password,vo.dest,vo.date_a,vo.date_r,vo.nb_ex,&vo.nb_p)!=EOF)
	{
		if(strcmp(mes,vo.dest)==0 && strcmp(n.login,vo.login)==0)
		{
			gtk_entry_set_text(GTK_ENTRY(in1),vo.date_a);
			gtk_entry_set_text(GTK_ENTRY(in2),vo.date_r);
			gtk_entry_set_text(GTK_ENTRY(in3),vo.nb_ex);
			gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin),vo.nb_p);
		}
	}
	fclose(f3);
	fclose(ftemp);
}


void
on_buttonModifvocli_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_buttonref4_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*in1,*in2,*combobox1;
	FILE*f4;
	char mes[50];
	resvol v;
	nouveau n;
	FILE*ftemp;
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	window1=lookup_widget(button,"interface36");
	in1=lookup_widget(window1,"entryAA9");
	in2=lookup_widget(window1,"entryAA10");
	combobox1=lookup_widget(window1,"combobox1009");
	strcpy(mes,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
	f4=fopen("/home/skander/Desktop/sky-travel/src/reservationvol.txt","r");
	while(fscanf(f4,"%s %s %s %s %s %s %s\n",v.login,v.password,v.dest,v.comp,v.type_vol,v.date_a,v.date_r)!=EOF)
	{
		if(strcmp(mes,v.dest)==0 && strcmp(n.login,v.login)==0)
		{
			gtk_entry_set_text(GTK_ENTRY(in1),v.date_a);
			gtk_entry_set_text(GTK_ENTRY(in2),v.date_r);
		}
	}
	fclose(f4);
	fclose(ftemp);
}


void
on_buttonModifvolcli_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_buttonretrc_enter                   (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window3,*window2,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	window2=lookup_widget(button,"interface35");
	window3=lookup_widget(button,"interface3");
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	gtk_widget_destroy(window2);
	window3=create_interface3();
	gtk_widget_show(window3);
	output1=lookup_widget(window3,"label18");
	output2=lookup_widget(window3,"label19");
	output3=lookup_widget(window3,"label20");
	output4=lookup_widget(window3,"label21");
	output5=lookup_widget(window3,"label22");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);	
}



void
on_buttonresvc_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*input1,*combobox;
	char date_r[50];
	nouveau n;
	vol v1;
	FILE*f;
	FILE*ftemp;
	FILE*f1;
	char type_v[50];
	window1=lookup_widget(button,"interface35");
	combobox=lookup_widget(window1,"combobox1010");
	input1=lookup_widget(window1,"entry84");
	f=fopen("/home/skander/Desktop/sky-travel/src/voltemporel.txt","r");
	f1=fopen("/home/skander/Desktop/sky-travel/src/reservationvol.txt","a+");
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11","r");
	fscanf(f,"%s %s %s %s %s %s %d\n",v1.dep,v1.dest,v1.comp,v1.date,v1.prix,v1.pro,&v1.id);
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	if(strcmp("Aller simple",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
	{
	 	strcpy(type_v,"aller_simple");
		strcpy(date_r,"-");
	}
	else
	{
		strcpy(date_r,gtk_entry_get_text(input1));
		strcpy(type_v,"aller_retour");
	}
	fprintf(f1,"%s %s %s %s %s %s %s\n",n.login,n.password,v1.dest,v1.comp,v1.date,date_r,type_v);
	fclose(f);
	fclose(f1);
	fclose(ftemp);
}


void
on_buttonAfflvRa_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*in1,*in2,*out1,*out2,*out3,*out4,*out5;
	FILE*f;
	char type[50],nch[50];
	lv lv;
	f=fopen("/home/skander/Desktop/sky-travel/src/lv.txt","r");
	window1=lookup_widget(button,"interface16");
	in1=lookup_widget(window1,"entry30");
	in2=lookup_widget(window1,"entry31");
	out1=lookup_widget(window1,"label932");
	out2=lookup_widget(window1,"label934");
	out3=lookup_widget(window1,"label936");
	out4=lookup_widget(window1,"label938");
	out5=lookup_widget(window1,"label940");
	strcpy(type,gtk_entry_get_text(GTK_ENTRY(in1)));
	strcpy(nch,gtk_entry_get_text(GTK_ENTRY(in2)));
	while(fscanf(f,"%s %s %s %s %s %s %d\n",lv.type,lv.nch,lv.date_a,lv.date_r,lv.prix,lv.promo,&lv.id)!=EOF)
    	{
        	if(strcmp(lv.type,type)!=0 && strcmp(lv.nch,nch)!=0)
        		{
				gtk_label_set_text(GTK_LABEL(out1),lv.type);
				gtk_label_set_text(GTK_LABEL(out2),lv.nch);
				gtk_label_set_text(GTK_LABEL(out3),lv.prix);
				gtk_label_set_text(GTK_LABEL(out4),lv.date_a);
				gtk_label_set_text(GTK_LABEL(out5),lv.date_r);
			}
	}
	fclose(f);
}


void
on_buttonratata_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window7,*window3,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(f,"%s %s %s %s %s %s",n.nom,n.login,n.password,n.email,n.cin,n.num);
	window3=lookup_widget(button,"interface3");
	window3=create_interface3();
	output1=lookup_widget(window3,"label18");
	output2=lookup_widget(window3,"label19");
	output3=lookup_widget(window3,"label20");
	output4=lookup_widget(window3,"label21");
	output5=lookup_widget(window3,"label22");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);		
	gtk_widget_show(window3);
	window7=lookup_widget(button,"interface36");
	gtk_widget_destroy(window7);
	fclose(f);
	
}


void
on_buttonrvol_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*input3,*input1,*input2,*combobox1,*combobox2;
	char date_a[50],date_r[50];
	nouveau n;
	vol v1;
	FILE*f;
	FILE*ftemp;
	FILE*f1;
	char type_v[50];
	window1=lookup_widget(button,"interface35");
	input1=lookup_widget(window1,"entry72");
	input2=lookup_widget(window1,"entry73");
	input3=lookup_widget(window1,"entry71");
	combobox1=lookup_widget(window1,"combobox2005");
	combobox2=lookup_widget(window1,"combobox1003");
	f=fopen("/home/skander/Desktop/sky-travel/src/voltemporel.txt","r");
	f1=fopen("/home/skander/Desktop/sky-travel/src/reservationvol.txt","a+");
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(f,"%s %s %s %s %s %s %d\n",v1.dep,v1.dest,v1.comp,v1.date,v1.prix,v1.pro,&v1.id);
	
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	if(strcmp("Aller simple",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
		{
			
			strcpy(type_v,"aller_simple");
			strcpy(date_a,gtk_entry_get_text(input1));
			strcpy(date_r,"-");	
		}
	else
		{	
			strcpy(date_r,gtk_entry_get_text(input2));
			strcpy(date_a,gtk_entry_get_text(input1));
			strcpy(v1.comp,gtk_entry_get_text(input3));
			strcpy(type_v,"aller_retour");		
		}
	fprintf(f1,"%s %s %s %s %s %s %s\n",n.login,n.password,v1.dest,v1.comp,type_v,date_a,date_r); 
	fclose(f);
	fclose(ftemp);
	fclose(f1);
}


void
on_buttonretrvol_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window3,*window2,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	window2=lookup_widget(button,"interface35");
	window3=lookup_widget(button,"interface3");
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	gtk_widget_destroy(window2);
	window3=create_interface3();
	gtk_widget_show(window3);
	output1=lookup_widget(window3,"label18");
	output2=lookup_widget(window3,"label19");
	output3=lookup_widget(window3,"label20");
	output4=lookup_widget(window3,"label21");
	output5=lookup_widget(window3,"label22");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
}


void
on_buttonresvoc_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*input1,*input2,*input3,*input4,*output1;
	FILE*f;
	FILE*ftemp;
	FILE*f1;
	nouveau n;
	voyage v1;
	char date_a[50],date_r[50],nbr_ex[50],nbr_personne[50],mes[50];
	window1=lookup_widget(button,"interface37");
	input1=lookup_widget(window1,"entry75");
	input2=lookup_widget(window1,"entry76");
	input3=lookup_widget(window1,"entry77");
	input4=lookup_widget(window1,"entry78");	
	output1=lookup_widget(window1,"label977");
	strcpy(date_r,gtk_entry_get_text(input2));
	strcpy(date_a,gtk_entry_get_text(input1));
	strcpy(nbr_ex,gtk_entry_get_text(input3));
	strcpy(nbr_personne,gtk_entry_get_text(input4));
	
	strcpy(mes,"reservation réussite");
	f=fopen("/home/skander/Desktop/sky-travel/src/voyagetemporel.txt","r");
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	f1=fopen("/home/skander/Desktop/sky-travel/src/resvoyage.txt","a+");
	fscanf(f,"%s %s %s %s %s %d %d %s %d\n",v1.dest,v1.date_a,v1.date_r,v1.nom_hotel,v1.type_trans,&v1.prix,&v1.disp,v1.pro,&v1.id);
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);	
	fprintf(f1,"%s %s %s %s %s %s %s\n",n.login,n.password,v1.dest,date_a,date_r,nbr_ex,nbr_personne);
	gtk_label_set_text(GTK_LABEL(output1),mes);
	fclose(f);
	fclose(f1);
	fclose(ftemp);
}


void
on_buttonretavc_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window3,*window2,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	window2=lookup_widget(button,"interface37");
	window3=lookup_widget(button,"interface3");
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	gtk_widget_destroy(window2);
	window3=create_interface3();
	gtk_widget_show(window3);
	output1=lookup_widget(window3,"label18");
	output2=lookup_widget(window3,"label19");
	output3=lookup_widget(window3,"label20");
	output4=lookup_widget(window3,"label21");
	output5=lookup_widget(window3,"label22");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
}


void
on_buttonresvoic_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*input1,*input2,*input3,*input4,*output1;
	FILE*f;
	FILE*ftemp;
	FILE*f1;
	nouveau n;
	lv lv;
	char date_a[50],date_r[50],nbr_ex[50],nbr_personne[50],mes[50];
	window1=lookup_widget(button,"interface38");
	input1=lookup_widget(window1,"entry79");
	input2=lookup_widget(window1,"entry80");
	output1=lookup_widget(window1,"label982");
	strcpy(date_r,gtk_entry_get_text(input2));
	strcpy(date_a,gtk_entry_get_text(input1));
	strcpy(mes,"reservation réussite");
	f=fopen("/home/skander/Desktop/sky-travel/src/lvtemporel.txt","r");
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	f1=fopen("/home/skander/Desktop/sky-travel/src/reslv.txt","a+");
	fscanf(f,"%s %s %s %s %s %s %d\n",lv.type,lv.nch,lv.date_a,lv.date_r,lv.prix,lv.promo,&lv.id);
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);	
	fprintf(f1,"%s %s %s %s %s\n",n.login,n.password,lv.type,date_a,date_r);
	gtk_label_set_text(GTK_LABEL(output1),mes);
	fclose(f);
	fclose(f1);
	fclose(ftemp);
}


void
on_buttonrretvoic_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *window3,*window2,*output1,*output2,*output3,*output4,*output5;
	FILE*f;
	nouveau n;
	window2=lookup_widget(button,"interface38");
	window3=lookup_widget(button,"interface3");
	f=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	gtk_widget_destroy(window2);
	window3=create_interface3();
	gtk_widget_show(window3);
	output1=lookup_widget(window3,"label18");
	output2=lookup_widget(window3,"label19");
	output3=lookup_widget(window3,"label20");
	output4=lookup_widget(window3,"label21");
	output5=lookup_widget(window3,"label22");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
}


void on_buttonaffrec_clicked (GtkWidget *objet,gpointer user_data)
{
	GtkWidget *window1;
	GtkWidget *treeview6;
	window1=lookup_widget(objet,"interface3");
	treeview6=lookup_widget(window1,"treeview50");
	afficher_reclamationclient(treeview6);
}

void on_buttonajrec_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window3,*window1;
	window3=lookup_widget(button,"interface3");
	window1=lookup_widget(button,"interface50");
	gtk_widget_destroy(window3);
	window1=create_interface50();
	gtk_widget_show(window1);
}

void on_buttonretouraj_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window1,*window3,*output1,*output2,*output3,*output4,*output5;
	FILE*ftemp;
	nouveau n;
	window3=lookup_widget(button,"interface50");
	window1=lookup_widget(button,"interface3");
	gtk_widget_destroy(window3);
	window1=create_interface3();
        ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window1,"label18");
	output2=lookup_widget(window1,"label19");
	output3=lookup_widget(window1,"label20");
	output4=lookup_widget(window1,"label21");
	output5=lookup_widget(window1,"label22");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window1);
	fclose(ftemp);
}

void on_buttonajreccl_clicked (GtkWidget *button,gpointer user_data)
{
	Reclamation lv;
	FILE*f;
	FILE*ftemp;
	FILE*f1;
	nouveau n;
	GtkWidget *window14,*window6,*input1,*input2,*input3,*input4,*input5,*input6,*output1,*output2,*output3,*output4,*output5;
	window6=lookup_widget(button,"interface3");
	window14=lookup_widget(button,"interface50");
	input1=lookup_widget(window14,"entry150");
	input2=lookup_widget(window14,"entry151");
	input3=lookup_widget(window14,"entry152");
	input4=lookup_widget(window14,"entry153");
	input5=lookup_widget(window14,"entry154");
        input6=lookup_widget(window14,"entry155");
        strcpy(lv.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(lv.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(lv.adresse,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(lv.telephone,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(lv.objet,gtk_entry_get_text(GTK_ENTRY(input5)));
        strcpy(lv.reclamation,gtk_entry_get_text(GTK_ENTRY(input6)));
	f=fopen("/home/skander/Desktop/sky-travel/src/reclamation.txt","a+");
   	fprintf(f,"%s %s %s %s %s %s\n",lv.nom,lv.prenom,lv.adresse,lv.telephone,lv.objet,lv.reclamation);
	fclose(f);
	/*f1=fopen("/home/skander/Desktop/sky-travel/src/reclamationaff.txt","a+");
   	fprintf(f1,"%s %s %s %s %s \n",lv.nom,lv.prenom,lv.adresse,lv.telephone,lv.objet);
	fclose(f1);*/
	/*gtk_widget_destroy(window14);
	window6=create_interface3();
	ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window6,"label18");
	output2=lookup_widget(window6,"label19");
	output3=lookup_widget(window6,"label20");
	output4=lookup_widget(window6,"label21");
	output5=lookup_widget(window6,"label22");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window6);
	fclose(ftemp);
}






void on_buttonmodcli_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window3,*window1;
	window3=lookup_widget(button,"interface3");
	window1=lookup_widget(button,"interface53");
	gtk_widget_destroy(window3);
	window1=create_interface53();
	gtk_widget_show(window1);
}





void on_buttonsuppcli_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window3,*window1;
	window3=lookup_widget(button,"interface3");
	window1=lookup_widget(button,"interface51");
	gtk_widget_destroy(window3);
	window1=create_interface51();
	gtk_widget_show(window1);

}


void on_buttonretoursupp_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window1,*window3,*output1,*output2,*output3,*output4,*output5;
	FILE*ftemp;
	nouveau n;
	window3=lookup_widget(button,"interface51");
	window1=lookup_widget(button,"interface3");
	gtk_widget_destroy(window3);
	window1=create_interface3();
        ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window1,"label18");
	output2=lookup_widget(window1,"label19");
	output3=lookup_widget(window1,"label20");
	output4=lookup_widget(window1,"label21");
	output5=lookup_widget(window1,"label22");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window1);
	fclose(ftemp);
}


void on_buttonsuppcli1_clicked (GtkWidget *button,gpointer user_data)
{
	Reclamation v;
	nouveau n;
	FILE*ftemp;
	char erreur[50];
	char nom[50];
	char prenom[50];
	char objet[50];
	FILE*f;
	GtkWidget *window12,*window6,*input1,*input2,*input3,*output1,*output2,*output3,*output4,*output5,*output6;
	window6=lookup_widget(button,"interface3");
	window12=lookup_widget(button,"interface51");
	input1=lookup_widget(window12,"entry156");
	input2=lookup_widget(window12,"entry157");
	input3=lookup_widget(window12,"entry158");
	strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(objet,gtk_entry_get_text(GTK_ENTRY(input3)));
	output6=lookup_widget(window12,"label2000");
	f=fopen("/home/skander/Desktop/sky-travel/src/reclamation.txt","r");
	while(fscanf(f,"%s %s %s %s %s %s\n",v.nom,v.prenom,v.adresse,v.telephone,v.objet,v.reclamation)!=EOF)
	{

	if(strcmp(nom,v.nom)==0 && strcmp(prenom,v.prenom)==0 && strcmp(objet,v.objet)==0)

			{


			supprimerrec(v.nom,v.prenom,v.objet);

			gtk_widget_destroy(window12);
			window6=create_interface3();
			gtk_widget_show(window6);
			ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
			fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
			output1=lookup_widget(window6,"label18");
			output2=lookup_widget(window6,"label19");
			output3=lookup_widget(window6,"label20");
			output4=lookup_widget(window6,"label21");
			output5=lookup_widget(window6,"label22");
			gtk_label_set_text(GTK_LABEL(output1),n.nom);
			gtk_label_set_text(GTK_LABEL(output2),n.login);
			gtk_label_set_text(GTK_LABEL(output3),n.email);
			gtk_label_set_text(GTK_LABEL(output4),n.cin);
			gtk_label_set_text(GTK_LABEL(output5),n.num);
			gtk_widget_show(window6);
			fclose(ftemp);
			}
			
	else
			{
				strcpy(erreur,"Cette reclamation n'existe pas");
				gtk_label_set_text(GTK_LABEL(output6),erreur);
			}
}
	fclose(f);

}


void on_buttonaffpro_clicked (GtkWidget *objet,gpointer user_data)
{
	GtkWidget *window1;
	GtkWidget *treeview6;
	window1=lookup_widget(objet,"interface5");
	treeview6=lookup_widget(window1,"treeview51");
	afficher_reclamation(treeview6);
}


void on_buttonaffagent_clicked (GtkWidget *objet,gpointer user_data)
{
	GtkWidget *window1;
	GtkWidget *treeview6;
	window1=lookup_widget(objet,"interface6");
	treeview6=lookup_widget(window1,"treeview52");
	afficher_reclamation(treeview6);
}


void on_buttonrepagent_clicked(GtkWidget *button,gpointer user_data)
{
	GtkWidget *window3,*window1;
	window3=lookup_widget(button,"interface6");
	window1=lookup_widget(button,"interface52");
	gtk_widget_destroy(window3);
	window1=create_interface52();
	gtk_widget_show(window1);
}


void on_buttonretourrepag_clicked (GtkWidget *button,gpointer user_data)
{


	GtkWidget *window1,*window3,*output1,*output2,*output3,*output4,*output5;
	FILE*ftemp;
	nouveau n;
	window3=lookup_widget(button,"interface52");
	window1=lookup_widget(button,"interface6");
	gtk_widget_destroy(window3);
	window1=create_interface6();
        ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window1,"label62");
	output2=lookup_widget(window1,"label61");
	output3=lookup_widget(window1,"label57");
	output4=lookup_widget(window1,"label58");
	output5=lookup_widget(window1,"label59");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window1);
	fclose(ftemp);

}


void on_buttonrepag_clicked (GtkWidget *button,gpointer user_data)
{	
	int x=0;
	char message[100];	
	Reponse lv;
	FILE*f;
	FILE*ftemp;
	nouveau n;
	GtkWidget *window14,*window6,*input1,*input2,*input3,*input4,*input5,*input6,*output1,*output2,*output3,*output4,*output5,*output6;
	window6=lookup_widget(button,"interface6");
	window14=lookup_widget(button,"interface52");
	input1=lookup_widget(window14,"entry159");
	input2=lookup_widget(window14,"entry160");
	input3=lookup_widget(window14,"entry161");
	input4=lookup_widget(window14,"entry162");
	input5=lookup_widget(window14,"entry163");
        input6=lookup_widget(window14,"entry164");
        strcpy(lv.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(lv.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(lv.adresse,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(lv.telephone,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(lv.objet,gtk_entry_get_text(GTK_ENTRY(input5)));
        strcpy(lv.reponse,gtk_entry_get_text(GTK_ENTRY(input6)));
	x=verifrec(lv.nom,lv.prenom,lv.objet);
	if (x!=0)
		{
			f=fopen("/home/skander/Desktop/sky-travel/src/reponsereclamation.txt","a+");
   			fprintf(f,"%s %s %s %s %s %s\n",lv.nom,lv.prenom,lv.adresse,lv.telephone,lv.objet,lv.reponse);
			fclose(f);
			gtk_widget_destroy(window14);
			window6=create_interface6();
			ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
			fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
			output1=lookup_widget(window6,"label62");
			output2=lookup_widget(window6,"label61");
			output3=lookup_widget(window6,"label57");
			output4=lookup_widget(window6,"label58");
			output5=lookup_widget(window6,"label59");
			gtk_label_set_text(GTK_LABEL(output1),n.nom);
			gtk_label_set_text(GTK_LABEL(output2),n.login);
			gtk_label_set_text(GTK_LABEL(output3),n.email);
			gtk_label_set_text(GTK_LABEL(output4),n.cin);
			gtk_label_set_text(GTK_LABEL(output5),n.num);
			gtk_widget_show(window6);
			fclose(ftemp);
		}
	else
		{
			output6=lookup_widget(window14,"label2007");
			strcpy(message,"verifier les coordonnees");
			gtk_label_set_text(GTK_LABEL(output6),message);
			
		}
}

  


void on_buttonretourmod_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window1,*window3,*output1,*output2,*output3,*output4,*output5;
	FILE*ftemp;
	nouveau n;
	window3=lookup_widget(button,"interface53");
	window1=lookup_widget(button,"interface3");
	gtk_widget_destroy(window3);
	window1=create_interface3();
        ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window1,"label18");
	output2=lookup_widget(window1,"label19");
	output3=lookup_widget(window1,"label20");
	output4=lookup_widget(window1,"label21");
	output5=lookup_widget(window1,"label22");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window1);
	fclose(ftemp);	
}






void on_buttonconfirmermod_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window16,*window6,*combobox4,*input1,*input2,*input3,*output1,*output2,*output3,*output4,*output5,*output6;	
	char mes[50],erreur[50];
	nouveau n;
	char nom[50],prenom[50];
	FILE*f;
	FILE*ftemp;
	FILE*F;
	FILE*F1;
	Reclamation lv;
	window6=lookup_widget(button,"interface3");
	window16=lookup_widget(button,"interface53");
	combobox4=lookup_widget(window16,"combobox1012");
	input1=lookup_widget(window16,"entry165");
	input2=lookup_widget(window16,"entry166");
	input3=lookup_widget(window16,"entry167");
	output6=lookup_widget(window16,"label2010");
	strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
	f=fopen("/home/skander/Desktop/sky-travel/src/reclamation.txt","r");
	while(fscanf(f,"%s %s %s %s %s %s\n",lv.nom,lv.prenom,lv.adresse,lv.telephone,lv.objet,lv.reclamation)!=EOF)
	{
			if(strcmp(nom,lv.nom)==0 && strcmp(prenom,lv.prenom)==0)

			{
				strcpy(mes,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4)));
				if(strcmp(mes,"Nom")==0)
				{
					supprimerr(nom,prenom);
//supprimerr1(nom,prenom);
					strcpy(lv.nom,gtk_entry_get_text(GTK_ENTRY(input3)));
				F=fopen("/home/skander/Desktop/sky-travel/src/reclamation.txt","a+");	
//F1=fopen("/home/skander/Desktop/sky-travel/src/reclamationaff.txt","a+");					
					fprintf(F,"%s %s %s %s %s %s\n",lv.nom,lv.prenom,lv.adresse,lv.telephone,lv.objet,lv.reclamation);
//fprintf(F1,"%s %s %s %s %s\n",lv.nom,lv.prenom,lv.adresse,lv.telephone,lv.objet);
					fclose(F);
//fclose(F1);								
				}
				else if(strcmp(mes,"Prenom")==0)
				{	
					supprimerr(nom,prenom);
//supprimerr1(nom,prenom);
					strcpy(lv.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
				F=fopen("/home/skander/Desktop/sky-travel/src/reclamation.txt","a+");	
//F1=fopen("/home/skander/Desktop/sky-travel/src/reclamationaff.txt","a+");				
					fprintf(F,"%s %s %s %s %s %s\n",lv.nom,lv.prenom,lv.adresse,lv.telephone,lv.objet,lv.reclamation);
//fprintf(F1,"%s %s %s %s %s\n",lv.nom,lv.prenom,lv.adresse,lv.telephone,lv.objet);
					fclose(F);
//fclose(F1);	
				}
				else if(strcmp(mes,"Adresse")==0)
				{	
					supprimerr(nom,prenom);
//supprimerr1(nom,prenom);
					strcpy(lv.adresse,gtk_entry_get_text(GTK_ENTRY(input3)));
				  F=fopen("/home/skander/Desktop/sky-travel/src/reclamation.txt","a+");	
//F1=fopen("/home/skander/Desktop/sky-travel/src/reclamationaff.txt","a+");				
					fprintf(F,"%s %s %s %s %s %s\n",lv.nom,lv.prenom,lv.adresse,lv.telephone,lv.objet,lv.reclamation);
//fprintf(F1,"%s %s %s %s %s\n",lv.nom,lv.prenom,lv.adresse,lv.telephone,lv.objet);
					fclose(F);
//fclose(F1);	
				}
				else if(strcmp(mes,"Telephone")==0)
				{	
					supprimerr(nom,prenom);
//supprimerr1(nom,prenom);
					strcpy(lv.telephone,gtk_entry_get_text(GTK_ENTRY(input3)));
				F=fopen("/home/skander/Desktop/sky-travel/src/reclamation.txt","a+");
//F1=fopen("/home/skander/Desktop/sky-travel/src/reclamationaff.txt","a+");					
					fprintf(F,"%s %s %s %s %s %s\n",lv.nom,lv.prenom,lv.adresse,lv.telephone,lv.objet,lv.reclamation);
//fprintf(F1,"%s %s %s %s %s\n",lv.nom,lv.prenom,lv.adresse,lv.telephone,lv.objet);
					fclose(F);
//fclose(F1);	
				}
				else if(strcmp(mes,"Objet")==0)
				{	
					supprimerr(nom,prenom);
//supprimerr1(nom,prenom);
					strcpy(lv.objet,gtk_entry_get_text(GTK_ENTRY(input3)));
				F=fopen("/home/skander/Desktop/sky-travel/src/reclamation.txt","a+");	
//F1=fopen("/home/skander/Desktop/sky-travel/src/reclamationaff.txt","a+");				
					fprintf(F,"%s %s %s %s %s %s\n",lv.nom,lv.prenom,lv.adresse,lv.telephone,lv.objet,lv.reclamation);
//fprintf(F1,"%s %s %s %s %s\n",lv.nom,lv.prenom,lv.adresse,lv.telephone,lv.objet);
					fclose(F);
//fclose(F1);	
				}
				else 
				{	
					supprimerr(nom,prenom);
//supprimerr1(nom,prenom);
					strcpy(lv.reclamation,gtk_entry_get_text(GTK_ENTRY(input3)));
				F=fopen("/home/skander/Desktop/sky-travel/src/reclamation.txt","a+");
//F1=fopen("/home/skander/Desktop/sky-travel/src/reclamationaff.txt","a+");					
					fprintf(F,"%s %s %s %s %s %s\n",lv.nom,lv.prenom,lv.adresse,lv.telephone,lv.objet,lv.reclamation);
//fprintf(F1,"%s %s %s %s %s\n",lv.nom,lv.prenom,lv.adresse,lv.telephone,lv.objet);
					fclose(F);
//fclose(F1);	
				}
	
			gtk_widget_destroy(window16);
			window6=create_interface3();
			gtk_widget_show(window6);
			ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
			fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
			output1=lookup_widget(window6,"label18");
			output2=lookup_widget(window6,"label19");
			output3=lookup_widget(window6,"label20");
			output4=lookup_widget(window6,"label21");
			output5=lookup_widget(window6,"label22");
			gtk_label_set_text(GTK_LABEL(output1),n.nom);
			gtk_label_set_text(GTK_LABEL(output2),n.login);
			gtk_label_set_text(GTK_LABEL(output3),n.email);
			gtk_label_set_text(GTK_LABEL(output4),n.cin);
			gtk_label_set_text(GTK_LABEL(output5),n.num);
			gtk_widget_show(window6);
			fclose(ftemp);

			}
			else
			{
				strcpy(erreur,"Cette reclamation n'existe pas");
				gtk_label_set_text(GTK_LABEL(output6),erreur);
			}

			
		
     
	}
	fclose(f);
}


void on_buttonfacebook_clicked (GtkWidget *button,gpointer user_data)
{
 system("firefox https://www.facebook.com/sky-travel-110672630422711/?modal=admin_todo_tour");
}


void on_buttoninstagram_clicked (GtkWidget *button,gpointer user_data)
{
 system("firefox https://www.instagram.com/skytravel48/");
}


void on_buttoncameras_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window3,*window1;
	window3=lookup_widget(button,"interface5");
	window1=lookup_widget(button,"interface54");
	gtk_widget_destroy(window3);
	window1=create_interface54();
	gtk_widget_show(window1);
}


void on_buttoncamera1_clicked (GtkWidget *button,gpointer user_data)
{
system ("vlc /home/skander/Desktop/sky-travel/src/camera1.mp4");
}


void on_buttoncamera2_clicked (GtkWidget *button,gpointer user_data)
{
system ("vlc /home/skander/Desktop/sky-travel/src/camera2.mp4");
}


void on_buttonretourcampro_clicked (GtkWidget *button,gpointer user_data)
{
	GtkWidget *window1,*window3,*output1,*output2,*output3,*output4,*output5;
	FILE*ftemp;
	nouveau n;
	window3=lookup_widget(button,"interface54");
	window1=lookup_widget(button,"interface5");
	gtk_widget_destroy(window3);
	window1=create_interface5();
        ftemp=fopen("/home/skander/Desktop/sky-travel/src/temp11.txt","r");
	fscanf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id);
	output1=lookup_widget(window1,"label47");
	output2=lookup_widget(window1,"label46");
	output3=lookup_widget(window1,"label42");
	output4=lookup_widget(window1,"label43");
	output5=lookup_widget(window1,"label44");
	gtk_label_set_text(GTK_LABEL(output1),n.nom);
	gtk_label_set_text(GTK_LABEL(output2),n.login);
	gtk_label_set_text(GTK_LABEL(output3),n.email);
	gtk_label_set_text(GTK_LABEL(output4),n.cin);
	gtk_label_set_text(GTK_LABEL(output5),n.num);
	gtk_widget_show(window1);
	fclose(ftemp);
}


void on_buttonenvoyergmail_clicked (GtkWidget *button,gpointer user_data)
{
system("firefox https://accounts.google.com/ServiceLogin/signinchooser?elo=1&flowName=GlifWebSignIn&flowEntry=ServiceLogin");
}


void on_buttongmailpro_clicked (GtkWidget *button,gpointer user_data)
{
system("firefox https://mail.google.com/mail/u/0/#inbox");
}

void on_buttongmailagent_clicked (GtkWidget *button,gpointer user_data)
{
system("firefox https://mail.google.com/mail/u/0/#inbox");
}


void on_buttonyoutube_clicked (GtkWidget *button,gpointer user_data)
{
system("firefox https://www.youtube.com/channel/UCejGiAiRZjLMv0Hgo7d1haw");
}

*/
