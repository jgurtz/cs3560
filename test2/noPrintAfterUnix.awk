BEGIN {
    flag = 0
}
{
    printf (flag==0) ? $0"\n" : "\0"    # if no flag print line, else null char
    $0 ~ /^.*[Uu][Nn][Ii][Xx].*$/ ? flag = 1 : flag = 0     # set flag on match
}
