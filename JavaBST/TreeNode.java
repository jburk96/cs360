/*
	TreeNode.java - the purpose of this program is to take specified string 
	data and turn it into a node with three seperate pointers pointing to a 
	parent node, left child node, and a right child node. 
	
---------------------------------------------------------------------------

programmer:		Richard Croft

---------------------------------------------------------------------------
*/

public class TreeNode 
{
    private String data;
    private TreeNode lChild;
    private TreeNode rChild;
    private TreeNode parent;
    
    public TreeNode ( )
    {
    }
    
    public TreeNode ( String x )
    {
        this.setData ( x );
    }
    
    public void setData ( String x )
    {
        this.data = x;
    }
    
    public void setLChild ( TreeNode p )
    {
        this.lChild = p;
    }

    public void setRChild ( TreeNode p )
    {
        this.rChild = p;
    }

    public void setParent ( TreeNode p )
    {
        this.parent = p;
    }
    
    public String getData ( )
    {
        return this.data;
    }
    
    public TreeNode getLChild ( )
    {
        return this.lChild;
    }
    
    public TreeNode getRChild ( )
    {
        return this.rChild;
    }

    public TreeNode getParent ( )
    {
        return this.parent;
    }
    
/*
	copy - the purpose of this method is make an exact copy of the original 
	BST by copying the original root value and recursively copying all the 
	treenodes that come after the root. This method is given the original 
	root node and will return the copied root node that has the same 
	pointers and descendants as the original BST. 
	
----------------------------------------------------------------------

	Programmer - 	Jesse A. Burk
	Date - 	5/26/2017
	Class - 	CS 260

*/
    
    public TreeNode copy(TreeNode parent )
    {
    	TreeNode p = parent;
    	TreeNode clone = new TreeNode ();
    	clone.data = p.getData();
    	
    	if (p.getLChild() != null)
    	{
    		p = p.getLChild();
    		clone.setLChild(copy(p));
    		clone.getLChild().setParent(clone);
    		p = parent;
    	}
    		
    	if (p.getRChild() != null)
    	{
    		p = p.getRChild();
    		clone.setRChild(copy(p));
    		clone.getRChild().setParent(clone);
    		p=parent;
    	}
    	
    	return clone;
    }
} 
  
