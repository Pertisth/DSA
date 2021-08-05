import java.util.Scanner;

public class LinkedList {
	
	class Node{
		int data;
		Node next;
		Node(int val){
			this.data = val;
			this.next =  null;
		}
	}
	
	 Node head=null;
	 Node last=null;
	
	public void insert(int val)
	{
		Node temp = new Node(val);
		
		if(head == null)
		{
			head = temp;
			last =temp;
		}
		else
		{
			last.next = temp;
			last = last.next;
		}
	}
	
	public int middleNode() {
		Node fast = head;
		Node slow = head;
		
		while(fast!=null && fast.next!=null)
		{
			slow = slow.next;
			fast = fast.next.next;
		}
		return slow.data;
	}
	
	public void display() {
		Node curr = head;
		while(curr!=null)
		{
			if(curr.next!=null)
			{
				System.out.print(curr.data+"->");
				curr = curr.next;
			}
			else {
				System.out.print(curr.data);
				return;
			}
			
			
		}
	}
	
	

	public static void main(String[] args) {
		LinkedList list = new LinkedList();
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		while(n--!=0)
		{
			int a = sc.nextInt();
			list.insert(a);
		}
		System.out.print(list.middleNode());
		sc.close();
		return;
		

	}

}
