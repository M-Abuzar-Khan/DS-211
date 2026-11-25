#include<iostream>
template<typename T>
class bst{
	private:
		template <typename U>
		struct node{
			U val;
			node<U>*left,*right,*parent;
		};
		node<T>*head;
		public:
			bst(){
				head=new node<T>;
				head->left=head;
					head->right=head;
						head->parent=head;
			}
			void insert(const T&val){
				if(head->parent==head){
					node<T>*temp;
					temp=new node<T>;
					temp->val=val;
					temp->parent=head;
					temp->left=head;
					temp->right=head;
					
					head->parent=temp;
					head->left=temp;
					head->right=temp;
					
				}
			else{
			
			node*ptr=head->parent;
			while(1){
				node<T>*temp1;
				temp1=new node<T>;
				temp1->val=val;
				if(temp1->val>ptr->val){
					if(ptr->right==head){
						ptr->right=temp1;
						temp1->parent=ptr;
						temp1->left=head;
						temp1->right=head;
						head->right=temp1;
						break;	
					}
					else{
						ptr=ptr->right;
					}
				}
				else{
						if(temp1->val<ptr->val){
					if(ptr->left==head){
						ptr->left=temp1;
						temp1->parent=ptr;
						temp1->left=head;
						temp1->right=head;
						head->left=temp1;
						break;	
					}
					else{
						ptr=ptr->left;
					}
				}
				}
		}
			}
		}
};
int main(){
	bst <int> b;
	b.insert(1);
		b.insert(5);
			b.insert(8);
				b.insert(4);
					b.insert(3);
}
