#pragma once
#ifndef INCLUDED_TEMPLATEITERATOR_H
#define INCLUDED_TEMPLATEITERATOR_H

template <typename IterT>
struct Range {
   IterT begin_;
   IterT end_;

   IterT begin() { return begin_; }
   IterT end() { return end_; }

   Range(IterT begin, IterT end) : begin_(begin), end_(end) {}
};

template <typename IterT>
Range<IterT> make_range(IterT begin, IterT end) 
{
   return Range<IterT>(begin, end);
}

#endif // INCLUDED_TEMPLATEITERATOR_H