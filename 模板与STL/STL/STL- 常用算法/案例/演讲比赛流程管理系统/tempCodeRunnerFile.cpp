    for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
    {
        cout  << "选手编号：" << it->first 
            << " 姓名： " << it->second.m_Name 
            << " 成绩： " << it->second.m_Score[0] << endl;
    }