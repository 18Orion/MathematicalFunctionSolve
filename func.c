double funcion::solve(double x){
    double n1, n2, result=0;
    bool continueMultiplicating=false;
    vector<string> fn, fn2;
    for (int i = 0; i < fnVector.size(); i++) {
        if(fnVector[i]!=""){
            if(fnVector[i]=="x"){
                fn.push_back(to_string(x));
            }else{
                fn.push_back(fnVector[i]);
            }
        }
    }
    for (int i = 0; i < fn.size(); i++) {
        if(fn[i]=="^"){
            fn[i-1]=to_string(pow(stod(fn[i-1]), stod(fn[i+1])));
            fn.erase(fn.begin()+i+1);
            fn.erase(fn.begin()+i);
            i=i-1;
        }
    }
    for (int i = 0; i < fn.size(); i++) {
        if(fn[i]=="*"||fn[i]=="/"&&i!=0){
            if (continueMultiplicating){
                n1=result;
            }else{
                n1=stod(fn[i-1]);
            }
            n2=stod(fn[i+1]);
            if(fn[i]=="*"){
                result=(n1*n2);
            }
            if(fn[i]=="^"){
                result=pow(n1, n2);
            }
            if(fn[i]=="/"){
                result=(n1/n2);
            }
            continueMultiplicating=true;
        }else{
            if(isSum(fn[i])){
                if(result!=0){
                    fn2.push_back(to_string(result));
                    continueMultiplicating=false;
                    result=0;
                }
                fn2.push_back(fn[i]);
            }else{
                if(i==0&&isSum(fn[i+1])){
                    fn2.push_back(fn[i]);
                }else if(isSum(fn[i-1])){
                    if(fn[i]==fn[fn.size()-2]){
                        fn2.push_back(fn[i]);
                    }else if(isSum(fn[i+1])){
                        fn2.push_back(fn[i]);
                    }
                }
            }
        }
    }
    if(0==0){
        if(fn2.size()==1){
            result=stod(fn2[0]);
        }else{
            for (int i = 0; i < fn2.size(); i++) {
                if(i==0&&!isSum(fn2[0])){
                    result=result+stod(fn2[0]);
                }
                if(fn2[i]=="+"){
                    result=result+stod(fn2[i+1]);
                }
                if(fn2[i]=="-"){
                    result=result-stod(fn2[i+1]);
                }
            }
        }
    }else{
        for (int i = 0; i < fn2.size(); i++) {
            cout<<fn2[i]<<endl;
        }
        cout<<endl<<fn2.size();
    }
    return result;
}
