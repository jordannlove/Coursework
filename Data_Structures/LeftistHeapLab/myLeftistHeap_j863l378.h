//Jordan Love - 2905840

#include <vector>
#include <iostream>
#include <exception>


template <typename Comparable>
class myLeftistHeap
{
public:
    myLeftistHeap( )
    {
        root = nullptr;
    }

    myLeftistHeap( const myLeftistHeap & rhs )
    {
        root = clone(rhs.root);
    }

    myLeftistHeap( myLeftistHeap && rhs )
    {
        root = std::move(rhs.root);
    }

    ~myLeftistHeap( )
    {
        makeEmpty();
    }

    myLeftistHeap & operator=( const myLeftistHeap & rhs )
    {
        if ( this != &rhs )
        {
            makeEmpty();
            root = clone( rhs.root );
        }
        return *this;
    }

    myLeftistHeap & operator=( myLeftistHeap && rhs )
    {
        root = std::move( rhs.root );
        return *this;
    }

    bool isEmpty( ) const
    {
        return ( root == nullptr );
    }

    const Comparable & findMin( ) const
    {
        if ( !isEmpty() )
        {
            return ( root -> element );
        }
        else
        {
            throw std::underflow_error("Heap is empty; no min.");
        }
    }

    void insert( const Comparable & x )
    {
        root = merge( new LeftistNode{x}, root );
    }

    void insert( Comparable && x )
    {
        root = std::move( merge( new LeftistNode{x}, root ) );
    }

    void deleteMin( )
    {
        if ( !isEmpty() )
        {
            LeftistNode *temp = root;
            root = merge( root -> left, root -> right );
            delete temp;
        }
        else
        {
            return;
        }
    }

    void deleteMin( Comparable & minItem )
    {
        minItem = findMin();
        deleteMin();
    }

    void makeEmpty( )
    {
        while ( !isEmpty() )
        {
            deleteMin();
        }
    }

    void merge( myLeftistHeap & rhs )
    {
        if ( this == &rhs )
        {
            return; //base case
        }
        root = merge( root, rhs.root );
        rhs.root = nullptr;
    }

    void printPreOrder(void)
    {
        if( !isEmpty() )
        {
            preOrder(root);
            std::cout << '\n';
        }
    }
    
private:
    struct LeftistNode
    {
        Comparable element;
        LeftistNode *left;
        LeftistNode *right;
        int npl;
        LeftistNode( const Comparable & e, LeftistNode *lt = nullptr,
            LeftistNode *rt = nullptr, int np=0)
            : element{ e }, left{ lt }, right{ rt }, npl{ np}{}
        LeftistNode( Comparable && e, LeftistNode *lt = nullptr,
            LeftistNode *rt = nullptr, int np=0)
            : element{ std::move( e ) }, left{ lt }, right{ rt }, npl{ np}{}
    };

    LeftistNode *root;

    LeftistNode * merge( LeftistNode *h1, LeftistNode *h2 )
    {
        if (h1 == nullptr)
        {
            return h2;
        }
        if (h2 == nullptr)
        {
            return h1;
        }
        if ( (h1 -> element) < (h2 -> element) )
        {
            return merge1( h1, h2 );
        }
        else
        {
            return merge1( h2, h1 );
        }
    }

    LeftistNode * merge1( LeftistNode *h1, LeftistNode *h2 )
    {
        if ( h1 -> left == nullptr )
        {
            h1 -> left = h2;
        }
        else
        {
            h1 -> right = merge( h1 -> right, h2 );
            if ( (h1 -> left -> npl) < (h1 -> right -> npl) )
            {
                swapChildren( h1 );
            }
            h1 -> npl = h1 -> right -> npl + 1;
        }
        return h1;
    }

    void swapChildren( LeftistNode *t )
    {
        LeftistNode *temp = t -> left;
        t -> left = t -> right;
        t -> right = temp;
    }

    void reclaimMemory( LeftistNode *t )
    {
        if (t != NULL)
        {
            reclaimMemory(t -> left);
            reclaimMemory(t -> right);
            delete t;
        }
    }

    LeftistNode * clone( LeftistNode *t ) const
    {
        if ( t == NULL )
        {
            return NULL;
        }
        else
        {
            return new LeftistNode( t -> element, clone( t -> left ), clone( t -> right ), t -> npl );
        }
    }

    void preOrder( LeftistNode *t )
    {
        if ( t != NULL )
        {
            std::cout << t -> element << ' ';
            preOrder(t -> left);
            preOrder(t -> right);
        }
    }
};