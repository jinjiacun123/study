/*******************************************************************************
 * Copyright (c) 2021, Initialsoft, Inc.
 * All rights reserved.
 *
 * main : [description]
 *
 * filename : main.cc
 * author   : hunt978(hunt978@initialsoft.com)
 * create   : 2021-03-15 03:15:35 UTC
 * modified : 2021-03-17 16:24:15 UTC
\******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
// Headers
//
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Typedefs & Constants
//
#define nullptr NULL

////////////////////////////////////////////////////////////////////////////////
// Inner Scope Objects
//
struct Node {
  uint32_t fid;
  uint32_t tid;

  struct Node* prev;
  struct Node* next;
};

/**
 * @brief      insert a node into list
 *
 *             there are 4 strains for the container :
 *
 *               1) from id and to id **CANNOT** be the same
 *               2) it should **NOT** hold duplicated node
 *               3) it should **NOT** hold circled link
 *               4) fan-out is allowed while fan-in is **NOT**.
 *
 * @param      head  The head
 * @param[in]  fid   The fid
 * @param[in]  tid   The tid
 *
 * @return     new head
 */
struct Node* insert_node(struct Node* head, uint32_t fid, uint32_t tid)
{
  struct Node *p, *q;
  //if point myself,throw exception
  if(fid == tid) return NULL;
  
  //check is exists link relation
  if(head != NULL){
  	for(p = head; p != NULL; p=p->next){
		if(p->fid == fid
        	&& p->tid == tid){
			return NULL;
		}
  	}  
  }


  //check is exists circle relation
  //from tid to find reach fid,if true is circle
  p = head;
  int linkLen = 0;
  int nextValue = 0;
  while(p != NULL){linkLen++;p=p->next;}

  nextValue = tid;
  while(p != NULL){
	if(p->fid == nextValue){
		//find next node
		nextValue == p->tid;
		if(nextValue == fid)//exists circle
			return NULL;
		p = head;
	}
  } 


  //may insert
  struct Node * new;
  new = (struct Node *)malloc(sizeof(struct Node));
  if(new == NULL){
	return NULL;
  }
  new->fid = fid;
  new->tid = tid;
  if(head == NULL){
	new->next = NULL;
	new->prev = NULL;
	return new;
  }else if(head->next == NULL){
	new->next = NULL;
	new->prev = head;
	head->next = new;
  	return new;
  }else{	  
  	new->next = head->next;
  	head->next->prev = new;
  	head->next = new;
  	new->prev = head;
	return new;
  }

  return nullptr;
}

/**
 * @brief      remove a node from list
 *
 * @param      head  The head
 * @param[in]  fid   The fid
 * @param[in]  tid   The tid
 *
 * @return     new head
 */
struct Node* remove_node(struct Node* head, uint32_t fid, uint32_t tid)
{
  // \TODO add your code here

  //check is exists
  struct Node *p = head->next;
  struct Node *q;
  q = head;
  while(p != NULL){
	if(p->fid == fid
	&& p->tid == tid){
	 if(p ->next == NULL)
	 	q->next = NULL;
	 else if(p->prev == head){
		head->next = p->next;
		p->next->prev = head;
	 }		 
	 else{
		q->next = p->next;
		p->next->prev = q;
	 }
	 free(p);
	 break;
	}
	q = p;
	p = p->next;
  }

  return nullptr;
}

/**
 * @brief      Dumps a list.
 *
 * @param      head  The head
 */
void dump_list(struct Node* head)
{
  printf("---------------------------\n");
  struct Node* node = head;
  while (node) {
    printf("  %d -> %d\n", node->fid, node->tid);
    node = node->next;
  }
}

/**
 * @brief      Does a test.
 */
void do_test()
{
  struct Node* head = nullptr;

  head = insert_node(head, 1, 2);
  dump_list(head);
  head = insert_node(head, 2, 4);
  dump_list(head);
  head = insert_node(head, 2, 3);
  dump_list(head);
  head = insert_node(head, 3, 4);
  dump_list(head);
  head = insert_node(head, 4, 1);
  dump_list(head);
  head = insert_node(head, 1, 2);
  dump_list(head);

  while (head) {
    head = remove_node(head, head->fid, head->tid);
  }
}

////////////////////////////////////////////////////////////////////////////////
// Classes
//

////////////////////////////////////////////////////////////////////////////////
// Functions
//
int main(int argc, char const* argv[])
{
  do_test();

  return 0;
}

////////////////////////////////// EOF /////////////////////////////////////////
