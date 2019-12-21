NR > 2 {
    print prePrev
}
{  
    prePrev = prev
    prev = $0
}
