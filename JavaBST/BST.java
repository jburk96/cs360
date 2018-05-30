/*
	BST.java - The purpose of this program is to implement the basic 
	operations for a binary search tree. These operations include insert, 
	locate, delete, inOrder, toString, previous, next, copy, and equals. 
	The BST class has one instance variable called root that holds the root 
	node in the tree. This program has the ability to insert string data 
	and represent that data in alphabetical order using the binary search 
	tree. This program will not add any data into the tree if that data 
	is a duplicate of something already inside the tree. This program can 
	also delete any data within the tree and not corrupt the order of that 
	tree. This program is able to find any information that alphabetically 
	comes before or after a specific node within the tree. The program has 
	the ability to locate specific data within the tree if that data 
	exists. The program is able to copy the tree as a seperate tree and is 
	also able to see if the copy made is an exact copy using the equals 
	method. 
	
--------------------------------------------------------------------------

	Programmer:		Jesse A. Burk
	Date Due:	5/26/2017
	Class:	CS 260
	
--------------------------------------------------------------------------
*/

public class BST
{  
	private TreeNode root;
	
	public BST ()
	{
		this.root = null;
	}

/*
	public insert - the purpose of the public insert method is to determine 
	if the root is null or not. This method is given string data and will 
	return true if the data was inserted, or it will return false if the 
	data was not inserted. If the root is not null, the method will 
	recursivly call the private insert method. 
*/
   
    public boolean insert (String value)
    {
    	boolean success;
    	
    	if (this.root == null)
    	{
    		this.root = new TreeNode (value);
    		success = true;
    	}
    		
    	else
    		success = insert (this.root , value);
    		
    	return success;
    }
    
/*
	private insert - the purpose of the private insert method is to add 
	new information into the binary search tree in the correct order. This 
	method is given the root treenode as well as the string data that needs 
	to be inserted. This method will return true if the data was inserted, 
	or it will return false if the data was not inserted. This method will 
	recursivly call itself if the treenode given has children blocking the 
	spot that the new information needs to be inserted. 
*/
    
    private boolean insert (TreeNode p , String v)
    {
    	boolean success;
    	
    	if (p.getData().equalsIgnoreCase(v))
    	{
    		success = false;
    	}
    		
    	else
    	{ 
    		if (p.getData().compareToIgnoreCase(v) > 0)
    		{
    			if (p.getLChild() != null)
    			{
    				success = insert (p.getLChild() , v);
    			}
    		
    			else
    			{
    				TreeNode branch = new TreeNode (v);
    				p.setLChild(branch);
    				branch.setParent(p);
    				success = true;
    			}
    		}
    		
    		else 
    		{
    			if (p.getRChild() != null)
    			{
    				success = insert (p.getRChild() , v);
    			}
    		
    			else
    			{
    				TreeNode branch = new TreeNode (v);
    				p.setRChild(branch);
    				branch.setParent(p);
    				success = true;
    			}
    		}
    	}
    	return success;
    }
    
/*
	public insert - the purpose of this method is to determine if the string
	 data given is within the binary search tree. This method will return a 
	 treenode. The treenode returned will be null if the value given was 
	 not in the the tree or it will return the treenode that contains the 
	 desired information. This method will call the private locate in order 
	 to fulfill this process.
*/
    
    public TreeNode locate (String value)
    {
    	TreeNode p = this.root;
    	TreeNode q = null;
    	
    	if (p != null)
    	{
			if (p.getData().compareToIgnoreCase(value) == 0)
				q = p;
				
			else if (p.getData().compareToIgnoreCase(value) > 0)
				q = locate(p.getLChild() , value);
			
			else if (p.getData().compareToIgnoreCase(value) < 0)
				q = locate(p.getRChild() , value);
    	}
    	
    	return q;
    }
    
/*
	private insert - the purpose of this method is to determine if the 
	string data given is within the binary search tree. This method is given 
	a treenode as a starting position for the locate and string data that 
	needs to be located. This method will return a treenode. The treenode 
	returned will be null if the value given was not in the the tree or it 
	will return the treenode that contains the desired information. This 
	method will recursively call itself in order to fulfill this process.
*/

    private TreeNode locate (TreeNode p , String v)
    {
    	TreeNode q = null;
    	
    	if (p != null)
    	{
			if (p.getData().compareToIgnoreCase(v) == 0)
				q = p;
				
			else if (p.getData().compareToIgnoreCase(v) > 0)
				q = locate(p.getLChild() , v);
			
			else if (p.getData().compareToIgnoreCase(v) < 0)
				q = locate(p.getRChild() , v);
    	}
    	
    	return q;
    }

/*
	delete - the purpose of this method is to delete a specified treenode 
	that is given to this method. When deleting a treenode from the tree, 
	the deletion will not disrupt the necessary order of the tree. This 
	method does not return anything at all.
*/
    
    public void delete (TreeNode p)
    {
    	
    	if (p == this.root)
    	{
    		if (p.getLChild() != null && p.getRChild() != null)
    		{
				this.root = p.getLChild();
				TreeNode q = this.root;
				
				while (q.getRChild() != null)
					q = q.getRChild();
					
				q.setRChild(p.getRChild());
				p.getRChild().setParent(q);
				
				this.root.setParent(null);
				p.setLChild(null);
				p.setRChild(null);
			}
			
			else if (p.getLChild() != null && p.getRChild() == null)
			{
				this.root = p.getLChild();
				this.root.setParent(null);
				p.setLChild(null);
			}
			
			else if (p.getLChild() == null && p.getRChild() != null)
			{
				this.root = p.getRChild();
				this.root.setParent(null);
				p.setRChild(null);
			}
			
			else if (p.getLChild() == null && p.getRChild() == null)
			{
				this.root=null;
				p = null;
			}
    	}
    	
    	
    	else
    	{
			if (p.getData().compareToIgnoreCase(p.getParent()
			.getData()) < 0)
			{
				if (p.getLChild() == null && p.getRChild() == null)
					p.getParent().setLChild(null);
				
				else if (p.getLChild() != null && p.getRChild() == null)
				{
					p.getParent().setLChild(p.getLChild());
					p.getLChild().setParent(p.getParent());
				}
			
				else if (p.getLChild() == null && p.getRChild() != null)
				{
					p.getParent().setLChild(p.getRChild());
					p.getRChild().setParent(p.getParent());
				}
			
				else if (p.getLChild() != null && p.getRChild() != null)
				{
					TreeNode q = predecessor (p);
					q.setRChild(p.getRChild());
					p.getRChild().setParent(q);
					p.getParent().setLChild(p.getLChild());
					q.setParent(p.getParent());
				}
			}
		
			else
			{
				if (p.getLChild() == null && p.getRChild() == null)
					p.getParent().setRChild(null);
				
				else if (p.getLChild() != null && p.getRChild() == null)
				{
					p.getParent().setRChild(p.getLChild());
					p.getLChild().setParent(p.getParent());
				}
			
				else if (p.getLChild() == null && p.getRChild() != null)
				{
					p.getParent().setRChild(p.getRChild());
					p.getRChild().setParent(p.getParent());
				}
			
				else if (p.getLChild() != null && p.getRChild() != null)
				{
					TreeNode q = predecessor (p);
					q.setRChild(p.getRChild());
					p.getRChild().setParent(q);
					p.getParent().setRChild(p.getLChild());
					q.setParent(p.getParent());
				}
			}
		
			p.setParent(null);
		}
    }
/* 
	public inOrder - returns the private InOrder. When that happens, the 
	outputted string of the BST will be in alphabetical order.
*/
    
    public String inOrder()
    {
    	return "" + inOrder(this.root);
    }

/*
	private inOrder - this method is given the root value of the BST and 
	recursively places each value in the BST in alphabetical order as a 
	string and then returns the string version of the BST.
*/
   
    private String inOrder(TreeNode p)
    {
    	String output;
    	if (p != null)
    		output =  "" + inOrder(p.getLChild()) + "\n" + p.getData() 
    		+ "" + inOrder(p.getRChild());
    		
    	else
    		output = "";
    		
    	return output;
    }
    
// toString - will return the inOrder string of the binary search tree.

    public String toString ()
    {
    	String output = "\n" + inOrder();
    		
    	return output;
    }
    
/*
	predecessor - this method is given a treenode within the tree and will 
	determine what the treenode that comes alphabetically before the 
	specified treenode is. This method will then return the found treenode. 
*/
    
    public TreeNode predecessor (TreeNode p)
    {
    	TreeNode q = null;
    	
    	if (p.getLChild() != null)
    	{
    		q = p.getLChild();
    		
    		while (q.getRChild() != null)
    		{
    			q = q.getRChild();
    		}
    	}
    	
    	else if (p.getParent() != null)
    	{
    		q = p.getParent();
    		
    		while (q != null && p.getData().compareToIgnoreCase
    		(q.getData()) < 0 )
    		{
    			q = q.getParent();
    		}
    	}
    	
    	return q;
    }

/*
	successor - this method is given a treenode within the tree and will 
	determine what the treenode that comes alphabetically after the 
	specified treenode is. This method will then return the found treenode. 
*/
    public TreeNode successor (TreeNode p)
    {
    	TreeNode q = null;
    	
    	if (p.getRChild() != null)
    	{
    		q = p.getRChild();
    		
    		while (q.getLChild() != null)
    		{
    			q = q.getLChild();
    		}
    	}
    	
    	else if (p.getParent() != null)
    	{
    		q = p.getParent();
    		
    		while (q != null && p.getData().compareToIgnoreCase
    		(q.getData()) > 0)
    		{
    			q = q.getParent();
    		}
    	}
    	
    	return q;
    }
    
/*
	copy - the purpose of this method is to determine if the tree is null. 
	If the tree is null, the method will return a new BST that is also null. 
	If the tree is not null, the method will return a new BST that is an 
	exact copy of the original tree. In order to do this, the method calls 
	a seperate copy method within the TreeNode.java file. 
*/
    
	public BST copy()
	{
		BST q = new BST ();
			
		if (this.root != null)
		{
			TreeNode clone;
			clone = this.root.copy(this.root);
			q.root = clone;
		}
		
		else
			q.root = null;
		
		return q;
	}
	
/*
	public equals - this method is given a new BST that is supposed to be a 
	copy of the original BST and determines if the new BST is an exact copy 
	of the original. The method will return true if the new BST is an exact 
	copy of the original BST.
*/
	
	public boolean equals (BST tree)
	{
		boolean same = false;
		
		if (tree.root != null && this.root != null)
			same = equals (this.root , tree.root);
			
		else if (tree.root == null && this.root == null)
			same = true;

		return same;
	}
	
/*
	private equals - this method is given the original root and the copied 
	root and recursivly determines if each and every node that follows 
	the roots are exactly the same as each other. If that is the case, 
	the method will return true.
*/
	
	private boolean equals (TreeNode p , TreeNode q)
	{
		boolean same = true;
		boolean LEquals = false;
		boolean REquals = false;
			
		if (p.getData().equalsIgnoreCase(q.getData()))
		{
			
			if (p.getLChild() != null && q.getLChild() != null)
				LEquals = equals (p.getLChild() , q.getLChild());
				
			if (p.getRChild() != null && q.getRChild() != null)
				REquals = equals (p.getRChild() , q.getRChild());
				
			if (p.getRChild() == null && q.getRChild() == null)
				REquals = true;
				
			if (p.getLChild() == null && q.getLChild() == null)
				LEquals = true;
				
			if (LEquals == false || REquals == false)
				same = false;
				
		}
		
		else
			same = false;
		
		return same;
	}
	
	public int wordCount(int length)
	{
		return wordCount(this.root , length);
	}
	
	private int wordCount (TreeNode p , int length)
	{
		int count = 0;
		
		if (p != null && p.getData().length() >= length)
			count++;
			
		if (p.getRChild() != null)
			count = count + wordCount(p.getRChild() , length);	
			
		if (p.getLChild() != null)
			count = count + wordCount(p.getLChild() , length);
			
		return count;
	}
}
