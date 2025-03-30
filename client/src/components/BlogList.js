import React, { useState, useEffect } from 'react';
import axios from 'axios';

function BlogList() {
  const [posts, setPosts] = useState([]);

  useEffect(() => {
    const fetchPosts = async () => {
      const response = await axios.get('/api/posts');
      setPosts(response.data);
    };
    fetchPosts();
  }, []);

  return (
    <div className="blog-list">
      {posts.map(post => (
        <div key={post._id} className="blog-post">
          <h2>{post.title}</h2>
          <p>{post.summary}</p>
          <span>{new Date(post.createdAt).toLocaleDateString()}</span>
        </div>
      ))}
    </div>
  );
}

export default BlogList;