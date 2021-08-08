#ifndef INTARRAY_H_
#define INTARRAY_H_

#include <cassert>

struct IntArray
{
    IntArray() = default;

    IntArray(int length) : len(length)
    {
        assert(this->len >= 0);
        if(this->len > 0)
        {
            this->data = new int[this->len]{};
        }
    }

    IntArray(const IntArray& array)
    {
        this->len = array.size();
        setData(array);
    }

    IntArray& operator=(const IntArray& array)
    {
        if(this == &array)
        {
            return *this;
        }

        delete[] this->data;
        this->len = array.size();
        setData(array);

        return *this;
    }

    ~IntArray()
    {
        delete[] this->data;
    }

    void erase()
    {
        delete[] this->data;
        this->data = nullptr;
        this->len = 0;
    }

    int& operator [](int idx) const
    {
        assert(idx >= 0 and idx < this->len);
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
        this->len = newLen;
    }

    void resize(int newLen)
    {
        if(this->len == newLen)
        {
            return ;
        }

        if(newLen <= 0)
        {
            erase();
            return ;
        }

        int* tmpData = new int[newLen]{};
        if(this->len > 0)
        {
            int copyNum = newLen > this->len ? this->len : newLen;
            for(int idx = 0; idx < copyNum; ++idx)
            {
                tmpData[idx] = data[idx];
            }
        }

        delete[] this->data;
        this->data = tmpData;
        this->len = newLen;
    }

    void insertBefore(int value, int index)
    {
        assert(index >= 0 and index <= this->len);

        int* tmpData = new int[this->len + 1]{};
        copyBeforeData(tmpData, index);
        tmpData[index] = value;
        for(int after = index; after < this->len; ++after)
        {
            tmpData[after + 1] = this->data[after];
        }

        delete[] this->data;
        this->data = tmpData;
        ++this->len;
    }

    void remove(int index)
    {
        assert(index >= 0 and index < this->len);

        if(this->len == 1)
        {
            erase();
            return ;
        }

        int* tmpData = new int[this->len]{};
        copyBeforeData(tmpData, index);
        for(int after = index + 1; after < this->len; ++after)
        {
            tmpData[after - 1] = this->data[after];
        }

        delete[] this->data;
        this->data = tmpData;
        --this->len;
    }

    void insertAtBegining(int value)
    {
        insertBefore(value, 0);
    }

    void insertAtEnd(int value)
    {
        insertBefore(value, this->len);
    }

    int size() const
    {
        return this->len;
    }

private:
    void setData(const IntArray& array)
    {
        if(array.size() > 0)
        {
            this->data = new int[array.size()]{};
            for(int idx = 0; idx < array.size(); ++idx)
            {
                this->data[idx] = array[idx];
            }
        }
    }

    void copyBeforeData(int* tmpData, const int index) const
    {
        for(int before = 0; before < index; ++before)
        {
            tmpData[before] = this->data[before];
        }
    }

private:
    int len;
    int* data;
};

#endif /* INTARRAY_H_ */
