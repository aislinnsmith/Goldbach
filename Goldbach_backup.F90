module Prime_number
implicit none
  
contains
  
integer function GetNextPrime(a)
implicit none
integer :: a
integer :: b
b = a + 1
do
if (IsPrime(b)) then
GetNextPrime = b
       exit
end if
      b = b + 1
   end do
                 
end function
integer function GetPreviousPrime(a)
implicit none
integer :: a
integer :: b
integer :: start_num
start_num = a-1
do b = start_num,0,-1
     if (IsPrime(b)) then
         GetPreviousPrime = b
         exit
     end if
   end do
              
 end function
 logical function IsPrime(a)
   implicit none
   integer :: a
   integer :: b
   integer :: max_num
       
   max_num = a - 1
         
   do b = 2,max_num,1
     if (MOD(a,b) == 0) then
       IsPrime = .false.
       exit
     else
       IsPrime = .true.
     end if
end do
                  
 end function
                    
 end module
                    

program Goldbach
use Prime_Number 
implicit none
integer :: p = 1 
integer :: q = 1
integer :: r
integer :: a,b
integer :: rows 
integer :: sums
integer :: run
integer :: i
integer, dimension (1000,3) :: my_goldbach

do a  = 0,100,1
  p = GetNextPrime(p) 
!  print *,p
do
  q = GetNextPrime(q) 
  sums = p + (p-q) 
  print *, (p-q)
  if (IsPrime(sums)) then 
  r = sums
  !print *,r 
  my_goldbach(a,1) = r
  my_goldbach(a,2) = q
  my_goldbach(a,3) = q
  q = 1
  exit 
  end if 
end do 
end do 




end program 



