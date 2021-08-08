#ifndef INTARRAY_H_
#define INTARRAY_H_

#include <cassert>

struct IntArray
{
    IntArray() = default;

    IntArray(int length) : length(length)
    {
        assert(this->length >= 0);
        if(this->length > 0)
        {
            this->data = new int[this->length]{};
        }
    }

    ~IntArray()
    {
        delete[] this->data;
    }

    void erase()
    {
        delete[] this->data;
        this->data = nullptr;
        this->length = 0;
    }

    int& operator [](int idx) const
    {
        assert(idx >= 0 and idx < this->length);
        return this->data[idx];
    }

    void reallocate(int newLen)
    {
        erase();

        if(newLen <= 0)
        {
            return ;
        }

        this->data = new int[newLen]{};
        this->length = newLen;
    }

    void resize(int newLen)
    {
        if(this->length == newLen)
        {
            return ;
        }

        if(newLen <= 0)
        {
            erase();
            return ;
        }

        int* tmpData = new int[newLen]{};
        if(this->length > 0)
        {
            int copyNum = newLen > this->length ? this->length : newLen;
            for(int idx = 0; idx < copyNum; ++idx)
            {
                tmpData[idx] = data[idx];
            }
        }

        delete[] this->data;
        this->data = tmpData;
        this->length = newLen;
    }

    void insertBefore(int value, int index)
    {
        assert(index >= 0 and index <= this->length);

        int* tmpData = new int[this->length + 1]{};
        for(int before = 0; before < index; ++ before)
        {
            tmpData[before] = this->data[before];
        }
        tmpData[index] = value;
        for(int after = index; after < this->length; ++after)
        {
            tmpData[after + 1] = this->data[after];
        }

        delete[] this->data;
        this->data = tmpData;
        ++this->length;
    }

    void remove(int index)
    {
        assert(index >= 0 and index < this->length);

        if(this->length == 1)
        {
            erase();
            return ;
        }

        int* tmpData = new int[this->length]{};
        for(int before = 0; before < index; ++before)
        {
            tmpData[index] = this->data[index];
        }
        for(int after = index + 1; after < this->length; ++after)
        {
            tmpData[after - 1] = this->data[after];
        }

        delete[] this->data;
        this->data = tmpData;
        --this->length;
    }

    void insertAtBegining(int value)
    {
        insertBefore(value, 0);
    }

    void insertAtEnd(int value)
    {
        insertBefore(value, this->length);
    }

    int size() const
    {
        return this->length;
    }

private:
    int length;
    int* data;
};

#endif /* INTARRAY_H_ */
