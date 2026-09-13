int maxSubArray( int *nums, int numsSize ) {
    int soma = nums[0];
	int soma_max = nums[0];

    for ( int i = 1; i < numsSize; i++ ) {
        if ( soma > 0 ) {
            soma += nums[i];
        } else {
            soma = nums[i];
        }

        if ( soma > soma_max ) {
            soma_max = soma;
        }
    }

	return soma_max;
}
