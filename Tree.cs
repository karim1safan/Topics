using System;
using System.Collections.Generic;
using System.IO;

namespace ProgrammingBasics_DS
{
    internal class BTreeNode
    {
        public BTreeNode(int value)
        {
            this.value = value;
        }

        public int value = 0;
        public BTreeNode Right = null, Left = null;

        public void Insert(int value, ref string Path)
        {
            if (value <= this.value) //Going Left
            {
                Path += "Left,";
                if (this.Left == null)
                {
                    if (Path.Length > 1)
                        Path = Path.Substring(0, Path.Length - 1);
                    this.Left = new BTreeNode(value);
                }
                else
                    this.Left.Insert(value, ref Path);
            }
            else //Going Right
            {
                Path += "Right,";
                if (this.Right == null)
                {
                    if (Path.Length > 1)
                        Path = Path.Substring(0, Path.Length - 1);
                    this.Right = new BTreeNode(value);
                }
                else
                    this.Right.Insert(value, ref Path);

            }
        }

        public BTreeNode FindMax()
        {
            if (this == null)
                return null;
            else if (this.Right == null)
                return this;
            else
                return this.Right.FindMax();
        }

        public BTreeNode DeleteNode(int key)
        {
            if (this == null)
                return null;

            if (key < this.value)
                this.Left = this.Left?.DeleteNode(key);
            else if (key > this.value)
                this.Right = this.Right?.DeleteNode(key);
            else
            {
                // One child on the left-subtree
                if (this.Right == null)
                    return this.Left;
                else if (this.Left == null)
                    return this.Right; // One child on the right sub-tree

                BTreeNode max = this.Left.FindMax();
                this.value = max.value;
                this.Left = this.Left.DeleteNode(max.value);
            }

            return this;
        }

        public BTreeNode Get(int value, ref string Path)
        {
            if (value == this.value)
            {
                if (Path.Length > 1)
                    Path = Path.Substring(0, Path.Length - 1);
                return this;
            }
            else if (value < this.value) //Going Left
            {
                if (this.Left == null)
                {
                    Path = "Not Found";
                    return null;
                }
                else
                {
                    Path += "Left,";
                    return this.Left.Get(value, ref Path);
                }
            }
            else //Going Right
            {
                if (this.Right == null)
                {
                    Path = "Not Found";
                    return null;
                }
                else
                {
                    Path += "Right,";
                    return this.Right.Get(value, ref Path);
                }
            }
        }

        public void GetChildren(List<BTreeNode> ret)
        {
            if (Left != null)
            {
                ret.Add(Left);
                Left.GetChildren(ret);
            }

            if (Right != null)
            {
                ret.Add(Right);
                Right.GetChildren(ret);
            }
        }

        #region Print

        public string Suffix
        {
            get
            {
                if (Right != null && Left != null)
                    return " ──┤ ";
                else if (Right != null)
                    return " ──┘ ";
                else if (Left != null)
                    return " ──┐ ";
                else return "";
            }
        }

        #endregion
    }

    internal class BTree
    {
        public BTreeNode Root;

        public void Insert(int value, ref string Path)
        {
            if (Root == null)
                Root = new BTreeNode(value);
            else
                Root.Insert(value, ref Path);
        }

        public void Remove(int value)
        {
            if (Root != null)
                Root = Root.DeleteNode(value);
        }

        public BTreeNode Get(int value, ref string Path)
        {
            return Root.Get(value, ref Path);
        }

        #region Print

        private void Print(BTreeNode node, int depth)
        {
            if (node == null)
            {
                return;
            }

            Print(node.Right, depth + 1);

            Console.WriteLine($"{new string(' ', depth * 4)}{node.value}");

            Print(node.Left, depth + 1);
        }

        private void Print2(BTreeNode node, int depth)
        {
            if (node == null)
            {
                return;
            }

            Print2(node.Right, depth + 1);

            // Print node value
            Console.Write(new string(' ', depth * 6));
            Console.WriteLine(node.value);

            // Print edge to the left child
            if (node.Left != null)
            {
                Console.Write(new string(' ', (depth + 1) * 6 - 2));
                Console.WriteLine("└──");
            }

            Print2(node.Left, depth + 1);
        }

        private void Print3(BTreeNode node, int depth)
        {
            if (node == null)
            {
                return;
            }

            Print3(node.Right, depth + 1);

            // Print node value with proper indentation
            Console.Write(new string(' ', depth * 6));
            Console.WriteLine(node.value);

            // Print edge to the left child, if it exists
            if (node.Left != null)
            {
                // Print proper indentation for the edge
                Console.Write(new string(' ', depth * 6));
                Console.Write("└── ");
                Print3(node.Left, depth + 1);
            }
            else if (node.Right != null)
            {
                // Print empty space for missing left child
                Console.Write(new string(' ', (depth + 1) * 6));
                Console.WriteLine();
            }
            else
            {
                // Print empty space if no child exists
                Console.WriteLine();
            }
        }

        private void Print4(BTreeNode node, int depth)
        {
            if (node == null)
            {
                return;
            }

            Print4(node.Right, depth + 1);

            // Print node value with proper indentation
            Console.Write(new string(' ', depth * 6));
            Console.WriteLine(node.value);

            // Print edge to the left child, if it exists
            if (node.Left != null || node.Right != null)
            {
                // Print proper indentation and edge for the left child
                Console.Write(new string(' ', depth * 6));
                Console.Write(node.Right != null ? "└── " : "├── ");
                Print4(node.Left, depth + 1);
            }
        }

        private void Print5(BTreeNode node, int depth, string prefix = "")
        {
            if (node == null)
            {
                return;
            }

            Print5(node.Right, depth + 1, prefix + (node.Left != null ? " " : " "));

            // Print node value with proper indentation and prefix
            Console.Write(new string(' ', depth * 4));
            Console.WriteLine(prefix + node.value + node.Suffix);

            Print5(node.Left, depth + 1, prefix + (node.Right != null ? " " : " "));
        }

        public void Print(int i = 0)
        {
            if (i == 0)
                Print(Root, 0);
            else if (i == 2)
                Print2(Root, 0);
            else if (i == 3)
                Print3(Root, 0);
            else if (i == 4)
                Print4(Root, 0);
            else if (i == 5)
                Print5(Root, 0);
            else Console.WriteLine("No Implementation!");
        }

        #endregion

        public static void Main()
        {
            int[] vert = new int[] { 8, 6, 5, 7, 12, 10, 11, 1, 0, 2 };
            BTree t = new BTree();
            for (int i = 0; i < vert.Length; i++)
            {
                string Path = "Root,";
                t.Insert(vert[i], ref Path);
                Console.WriteLine($"Inserting item[{i + 1}]= {vert[i]} the Path is {Path}");
            }

            for (int i = vert.Length - 1; i >= 0; i--)
            {
                string Path = "Root,";
                t.Get(vert[i], ref Path);
                Console.WriteLine($"Getting item[{i + 1}]= {vert[i]} the Path is {Path}");
            }

            t.Print(5);
            string path = "";
            Console.ReadLine();
            t.Remove(6);
            t.Print(5);
            Console.ReadLine();
            t.Remove(12);
            t.Print(5);
        }
    }
}
