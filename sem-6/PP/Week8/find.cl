__kernel void find(__global char* A,__global char* B,__global int *n,__global int *len,__global int *ans)
{
	int id = get_global_id(0);
	int j = 0, flag = 1, diff = n[id + 1] - n[id] - 1;
	if (diff == *len)
	{
		for (int i = n[id] + 1; i < n[id + 1]; i++, j++)
		{
			if(A[i] != B[j])
			{
				flag=0;
				break;
			}
			
		}
	
		if(flag == 1)
	 		ans[id]++;
	}
}
